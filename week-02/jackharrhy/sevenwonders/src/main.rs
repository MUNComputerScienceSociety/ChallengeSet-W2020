use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let inp = stdin.lock().lines().next().unwrap().unwrap();

    let mut t: usize = 0;
    let mut c: usize = 0;
    let mut g: usize = 0;

    for card in inp.chars() {
        match card {
            'T' => t+=1,
            'C' => c+=1,
            _ => g+=1,
        }
    }

    let mut list = vec![t,c,g];
    list.sort();

    let result = t.pow(2) + c.pow(2) + g.pow(2) + list[0] * 7;
    println!("{}", result);
}
