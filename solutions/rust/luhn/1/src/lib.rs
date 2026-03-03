/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    let code: String = code.chars().filter(|c| !c.is_whitespace()).collect();

    if code.len() <= 1 || code.chars().any(|c| !c.is_digit(10)) {
        return false;
    }

    let mut new_code = String::new();
    for (i, c) in code.chars().enumerate() {
        if i+1 % 2 == 0  {
            new_code.push(c);
        }
        let dig = u8::from_str_radix(&c.to_string(), 10).unwrap();
        let mut new_dig = dig *2;
        if new_dig > 9 {
            new_dig -= 9;
        }
        new_code.push_str(&new_dig.to_string());
    }
    let sum: u32 = new_code.chars().map(|c| c.to_digit(10).unwrap()).sum();
    sum % 10 == 0
}
