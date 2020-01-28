use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut iter = stdin.lock().lines().map(|x| x.unwrap());
    iter.next();
    for line in iter {
        let line: String = line.split('\n').collect();
        let values: Vec<f64> = line.split(' ').map(|x| x.parse::<f64>().unwrap()).collect();
        let a = values[0];
        let b = values[1];
        let c = values[2];

        let div = (a / b) == c;
        let div_swap = (b / a) == c;
        let mul = (a * b) == c;
        let add = (a + b) == c;
        let sub = (a - b) == c;
        let sub_swap = (b - a) == c;

        if div || div_swap || mul || add || sub || sub_swap {
            println!("Possible");
        } else {
            println!("Impossible");
        }
    }
}
