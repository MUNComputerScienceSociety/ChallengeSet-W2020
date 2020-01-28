use std::io::{self, BufRead};

enum State {
    ReadCommand,
    SkipForward,
    SkipBackwards,
}

fn main() {
    let stdin = io::stdin();
    let inp = stdin.lock().lines().fold("".to_string(), |acum, x| acum + &x.unwrap());
    println!("inp: {}", inp);

    let mut read_head = 0usize;
    let mut pointer = 0usize;
    let mut cells : [u8; 16] = [0; 16];
    let mut state = State::ReadCommand;

    loop {
        let command = match inp.chars().nth(read_head) {
            Some(value) => value,
            None => break,
        };

        match state {
            State::SkipForward => {
                read_head += 1;
                if command == ']' {
                    state = State::ReadCommand;
                }
            },
            State::SkipBackwards => {
                if command == '[' {
                    state = State::ReadCommand;
                } else {
                    read_head -= 1;
                }
            },
            State::ReadCommand => {
                match command {
                    '>' => pointer += 1, // Move the pointer to the right
                    '<' => pointer -= 1, // Move the pointer to the left
                    '+' => cells[pointer] += 1, // Increment the memory cell under the pointer
                    '-' => cells[pointer] -= 1, // Decrement the memory cell under the pointer
                    '.' => println!("{}", cells[pointer] as char), // Output the character signified by the cell at the pointer
                    ',' => println!("!!!{}!!!", command), // Input a character and store it in the cell at the pointer
                    '[' => { // Jump past the matching ] if the cell under the pointer is 0
                        if cells[pointer] == 0 {
                            state = State::SkipForward;
                            continue;
                        }
                    }, 
                    ']' => { // Jump back to the matching [ if the cell under the pointer is nonzero 
                        if cells[pointer] != 0 {
                            state = State::SkipBackwards;
                            continue;
                        }
                    }, 
                    _ => continue,
                }
                read_head += 1
            },
        };

        let mut i = 0;
        for c in inp.chars() {
            if i == read_head {
                print!(" _");
            }
            print!("{}", c);
            if i == read_head {
                print!("_ ");
            }
            i += 1;
        }
        println!("");
        let mut i = 0;
        for c in cells.iter() {
            if i == pointer {
                print!(" _");
            }
            print!("{}", c);
            if i == pointer {
                print!("_ ");
            }
            i += 1;
        }
        println!("\n");
    };
}
