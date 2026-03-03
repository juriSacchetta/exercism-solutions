pub fn square_of_sum(n: u32) -> u32 {
   (1..=n).reduce(|x,y| x+y).unwrap().pow(2)
}

pub fn sum_of_squares(n: u32) -> u32 {
(1..=n).reduce(|x,y| x.pow(2) + y.pow(2)).unwrap()
}

pub fn difference(n: u32) -> u32 {
    let mut res: i64 = (square_of_sum(n) as i64) - (sum_of_squares(n) as i64);
    if res < 0 {
        res = -res;
    }
    res as u32
}
