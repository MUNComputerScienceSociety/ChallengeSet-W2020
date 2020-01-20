use std::io::{self, Read};

use permutohedron::Heap;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin();
    let mut handle = stdin.lock();
    handle.read_to_string(&mut buffer)?;

    let cleaned: String = buffer.split('\n').collect();

    let mut boxes: Vec<usize> = cleaned
        .split(' ')
        .map(|x| x.parse::<usize>().unwrap())
        .collect();
    let heights: Vec<usize> = boxes.split_off(6);

    let heap = Heap::new(&mut boxes);
    let mut permutations = Vec::new();
    for data in heap {
        permutations.push(data.clone());
    }

    let wanted_tower_a_height = heights[0];
    let wanted_tower_b_height = heights[1];

    for perm in permutations {
        let mut tower_a = perm[0..3].to_vec();
        let tower_a_height = tower_a.iter().fold(0, |acc, x| acc + x);

        let mut tower_b = perm[3..6].to_vec();
        let tower_b_height = tower_b.iter().fold(0, |acc, x| acc + x);

        if tower_a_height == wanted_tower_a_height && tower_b_height == wanted_tower_b_height {
            tower_a.sort();
            tower_a.reverse();
            tower_b.sort();
            tower_b.reverse();

            println!(
                "{} {} {} {} {} {}",
                tower_a[0], tower_a[1], tower_a[2], tower_b[0], tower_b[1], tower_b[2]
            );
            break;
        }
    }

    Ok(())
}
