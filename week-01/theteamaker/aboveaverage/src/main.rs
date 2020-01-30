use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let lines: Vec<String> = stdin.lock().lines().map(|x| x.unwrap()).collect();

    let iterative = lines[0].clone().to_string().parse::<i32>().unwrap();

    for i in 1..iterative + 1 {
        let current = &lines[i as usize];
        let sentence: Vec<&str> = current.split(" ").collect();
        let numbers: Vec<f64> = sentence.iter().map(|x| x.parse::<f64>().unwrap()).collect();

        let divisor = numbers[0] as i32;
        let mut average = 0.0;

        for i in 1..divisor + 1 {
            average = average + numbers[i as usize];
        }

        average = average / divisor as f64;

        let mut exceptional_students = 0;

        for i in 1..divisor + 1 {
            if numbers[i as usize] as f64 > average {
                exceptional_students = exceptional_students + 1;
            }
        }

        let percentage = exceptional_students as f64 / divisor as f64 * 100.0;

        println!("{:.3}%", percentage);
    }
}