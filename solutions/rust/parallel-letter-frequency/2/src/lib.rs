use std::collections::HashMap;

pub fn frequency(input: &[&str], worker_count: usize) -> HashMap<char, usize> {

    let single_threaded = |input: &[&str]| {
        let mut frequency = HashMap::new();
        for line in input {
            for c in line.chars() {
                if c.is_alphabetic() {
                    *frequency.entry(c.to_ascii_lowercase()).or_insert(0) += 1;
                }
            }
        }
        frequency
    };

    let multi_threaded = |input: &[&str], worker_count: usize| {
        use std::sync::{Arc, Mutex};
        use std::thread;

        let frequency = Arc::new(Mutex::new(HashMap::new()));
        let mut threads = vec![];

        for chunk in input.chunks(input.len() / worker_count) {
            let frequency = Arc::clone(&frequency);
            let chunk: Vec<String> = chunk.iter().map(|s| s.to_string().to_ascii_lowercase()).collect();
            threads.push(thread::spawn(move || {
                let mut frequency = frequency.lock().unwrap();
                for line in chunk {
                    for c in line.chars() {
                        if c.is_alphabetic() {
                            *frequency.entry(c).or_insert(0) += 1;
                        }
                    }
                }
            }));
        }

        for thread in threads {
            thread.join().unwrap();
        }

        Arc::try_unwrap(frequency).unwrap().into_inner().unwrap()
    };

    if input.is_empty() {
        return HashMap::new();
    }

    match worker_count {
        0 => panic!("worker_count must be greater than 0"),
        1 => single_threaded(input),
        _ => multi_threaded(input,  if input.len() < worker_count { input.len() } else { worker_count }),
    }
}