use std::io::{self, Read};

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin();
    let mut handle = stdin.lock();
    handle.read_to_string(&mut buffer)?;
    for s in buffer.split('-') {
        print!("{}", s.chars().nth(0).unwrap());
    }
    println!("");
    Ok(())
}
