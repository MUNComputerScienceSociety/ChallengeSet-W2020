use std::io::{self, Read};

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin();
    let mut handle = stdin.lock();
    handle.read_to_string(&mut buffer)?;

    let input: Vec<&str> = buffer.split('\n').collect();
    let (_, cases) = input.split_at(1);

    for case in cases {
        let marks: Vec<&str> = case.split(' ').collect();

        if marks.len() == 1 {
            continue;
        }

        let (_, marks) = marks.split_at(1);
        let mut best: usize = 0;

        let sum = marks.iter().fold(0, |acc, x| acc + x.parse::<usize>().unwrap());
        let avg = sum / marks.len();

        for mark in marks {
            if mark.parse::<usize>().unwrap() > avg {
                best += 1;
            }
        }

        println!("{:.3}%", ((best as f64) / (marks.len() as f64)) * 100_f64);
    }

    Ok(())
}
