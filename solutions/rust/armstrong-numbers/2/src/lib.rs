pub fn is_armstrong_number(num: u32) -> bool {
    let num_len  = num.to_string().len() as u32;
    u64::from(num) == num.to_string().chars().fold(0, |t: u64, x: char| (x.to_digit(10).unwrap() as u64).pow(num_len) + t)
}
