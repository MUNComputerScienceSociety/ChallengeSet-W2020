use regex::Regex;
use std::io::{self, BufRead};

fn main() {
    let room_regex =
        Regex::new(r"(([A-Z]  )|([A-Z]{2} )|([A-Z]{3}))((\d){4}([A-Z])?)($|\n)").unwrap();

    let stdin = io::stdin();
    for line in stdin.lock().lines() {
        println!(
            "{}",
            if room_regex.is_match(&line.unwrap()) {
                'Y'
            } else {
                'N'
            }
        );
    }
}
