#include <iostream>
#include <algorithm>
#include <vector>

int bits_number(int input_val) 
{
    int number = 0;
    while (input_val > 0) {
        number += input_val & 1;
        input_val >>= 1;
    }
    return number;
}

bool compare(int left, int right) 
{
    int left_bits = bits_number(left);
    int right_bits = bits_number(right);

    return left_bits < right_bits;
}

int main() 
{
    std::vector<int> numbers;
    int input_val;
    while (std::cin >> input_val) {
        numbers.push_back(input_val);
    }

    std::stable_sort(numbers.begin(), numbers.end(), compare);

     for (int elem : numbers) {
        std::cout << elem << std::endl;
    }

    return 0;
}
