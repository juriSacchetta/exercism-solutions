use std::fmt::Display;
#[derive(Debug, PartialEq)]
pub struct Clock {
    hours: i32,
    minutes: i32,
}

impl Clock {
    fn set(hours: i32, minutes: i32) -> Self {
        let mut new_hours = hours;
        let mut new_minutes = minutes;
        if new_minutes < 0 {
            new_hours -= 1;
            new_minutes += 60;
        }
        if new_hours < 0 {
            new_hours += 24;
        }
        new_hours += new_minutes / 60;
        new_minutes %= 60;
        new_hours %= 24;
        Self {
            hours: new_hours,
            minutes: new_minutes,
        }
    }
    pub fn new(hours: i32, minutes: i32) -> Self {
        Self::set(hours, minutes)
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Self::set(self.hours, self.minutes + minutes)
    }
}

impl Display for Clock {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{:02}:{:02}", self.hours, self.minutes)
    }
}
