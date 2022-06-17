def calculate_sense_of_life(input: float, strategy):
    result = (input * 2) / 3
    result += strategy(result)
    return result + 1.0


def basic_strategy(input: float):
    return input * 2.0;


def max_strategy(input: float):
    return input * 3.0;


print(calculate_sense_of_life(100, basic_strategy))
print(calculate_sense_of_life(100, max_strategy))
print(calculate_sense_of_life(100, lambda x: x * 4.0))