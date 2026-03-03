use std::collections::HashMap;
use std::sync::{Arc, Mutex};
use std::thread;

pub fn frequency(input: &[&str], worker_count: usize) -> HashMap<char, usize> {
    let input = input.to_owned();
    let result = Arc::new(Mutex::new(HashMap::<char, usize>::new()));
    let handlers = input.chunks(input.len() / worker_count)
        .map(|chunk| {
            let chunk = chunk.to_vec();
            thread::spawn(move || {
                let mut local_result = HashMap::<char, usize>::new();
                for line in chunk {
                    for c in line.chars() {
                        if c.is_alphabetic() {
                            *local_result.entry(c.to_ascii_lowercase()).or_insert(0) += 1;
                        }
                    }
                }
                local_result
            })
        });

    for handler in handlers {
        let local_result = handler.join().unwrap();
        let mut result = result.lock().unwrap();
        for (k, v) in local_result {
            *result.entry(k).or_insert(0) += v;
        }
    }
    Arc::try_unwrap(result).unwrap().into_inner().unwrap()
}