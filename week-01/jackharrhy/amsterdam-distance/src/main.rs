use std::f64::consts::PI;
use std::io::{self, BufRead};

fn stdin_line_to_values(line: &String) -> Vec<f64> {
    let cleaned: String = line.split('\n').collect();
    let line: Vec<&str> = cleaned.split(' ').collect();
    return line.iter().map(|x| x.parse::<f64>().unwrap()).collect();
}

struct Config {
    segments: f64,
    rings: f64,
    radius: f64,
}

struct Point {
    segment: f64,
    ring: f64,
}

impl Point {
    fn circ(&self, config: &Config) -> f64 {
        return (self.segment / config.segments) * PI;
    }
}

fn calc_dist(p1: &Point, p2: &Point, config: &Config) -> f64 {
    let dist = ((p1.ring - p2.ring).abs() / config.rings) * config.radius;
    let angle = (p1.circ(config) - p2.circ(config)).abs();
    let arc = (angle * (p2.ring / config.rings)) * config.radius;
    arc + dist
}

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let line1 = stdin_line_to_values(&lines.next().unwrap().unwrap());
    let config = Config {
        segments: line1[0],
        rings: line1[1],
        radius: line1[2],
    };

    let line2 = stdin_line_to_values(&lines.next().unwrap().unwrap());
    let p1 = Point {
        segment: line2[0],
        ring: line2[1],
    };
    let p2 = Point {
        segment: line2[2],
        ring: line2[3],
    };

    let mut least = calc_dist(&p1, &p2, &config);
    for a in 0..config.rings as usize {
        let a = a as f64;
        let a_shift = ((p1.ring - a).abs() / config.rings) * config.radius;
        for b in 0..config.rings as usize {
            let b = b as f64;
            let b_shift = ((p2.ring - b).abs() / config.rings) * config.radius;
            let result = calc_dist(
                &Point {
                    segment: p1.segment,
                    ring: a,
                },
                &Point {
                    segment: p2.segment,
                    ring: b,
                },
                &config,
            ) + a_shift
                + b_shift;
            if result < least {
                least = result;
            }
        }
    }

    println!("{}", least);

    Ok(())
}
