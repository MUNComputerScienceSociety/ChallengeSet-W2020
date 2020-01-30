use std::io::{self, BufRead};

fn main() {
    let mut line = String::new();
    let stdin = io::stdin();
    stdin.lock().read_line(&mut line).unwrap();
    
    let split_list: Vec<&str> = line.split('-').collect();

    let mut chars = String::new();
    
    for item in split_list {
        let to_add = item.chars().nth(0).unwrap();
        chars.push(to_add);
    }

    println!("{}", chars)
}