use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut iter = stdin.lock().lines().map(|x| x.unwrap());
    iter.next();
    for line in iter {
        println!("{}", line.chars().count());
    }
}
