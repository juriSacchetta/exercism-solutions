pub fn annotate(minefield: &[&str]) -> Vec<String> {
    let mut result = Vec::<String>::new();
    for (i, row) in minefield.iter().enumerate() {
        let mut new_row = String::new();
        for (j, cell) in row.chars().enumerate() {
            if cell == '*' {
                new_row.push('*');
            } else {
                let mut count = 0;
                for x in -1..=1 {
                    for y in -1..=1 {
                        if x == 0 && y == 0 {
                            continue;
                        }
                        let new_i = i as i32 + x;
                        let new_j = j as i32 + y;
                        if new_i >= 0
                            && new_i < minefield.len() as i32
                            && new_j >= 0
                            && new_j < row.len() as i32
                            && minefield[new_i as usize].chars().nth(new_j as usize).unwrap() == '*'
                        {
                            count += 1;
                        }
                    }
                }
                if count == 0 {
                    new_row.push(' ');
                } else {
                    new_row.push_str(&count.to_string());
                }
            }
        }
        result.push(new_row);
    }
    result
}
