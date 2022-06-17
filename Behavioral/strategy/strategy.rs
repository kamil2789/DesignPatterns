fn calculate_sense_of_life<F: Fn(f32) -> f32>(input: u32, strategy: F) -> f32 {
    let mut result: f32 = ((input * 2) / 3) as f32;
    result += strategy(result);
    result + 1.0
}

fn basic_strategy(input: f32) -> f32 {
    input * 2.0
}

fn max_strategy(input: f32) -> f32 {
    input * 3.0
}

fn main() {
    let mut result = calculate_sense_of_life(100, basic_strategy);
    println!("{result}");
    result = calculate_sense_of_life(100, max_strategy);
    println!("{result}");
    result = calculate_sense_of_life(100, |x| x * 4.0);
    println!("{result}");
}