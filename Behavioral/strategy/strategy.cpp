#include <functional>
#include <iostream>

float calculate_sense_of_life(float input, std::function<float (float)> strategy)
{
    float result = (input * 2) / 3;
    result += strategy(result);
    return result + 1.0;
}

float basic_strategy(float input)
{
    return input * 2.0;
}

float max_strategy(float input)
{
    return input * 3.0;
}

int main()
{
    std::cout<<calculate_sense_of_life(100, basic_strategy)<<std::endl;
    std::cout<<calculate_sense_of_life(100, max_strategy)<<std::endl;
    std::cout<<calculate_sense_of_life(100, [](float x){ return x * 4.0;})<<std::endl;
}