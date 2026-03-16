#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Summer {
public:
    double total;
    int counter;
    Summer() : total(0.0), counter(0) {}
    void operator()(double value) {
        total += value;
        counter++;
    }
};

int main() {
    std::vector<double> numbers;
    double input;
    while (std::cin >> input) {
        numbers.push_back(input);
    }

    int total_size = numbers.size();
    int step1 = total_size / 10;

    std::sort(numbers.begin() + step1, numbers.end() - step1);

    int middle_size = total_size - 2 * step1;
    int step2 = middle_size / 10;

    auto left_border = numbers.begin() + step1 + step2;
    auto right_border = numbers.end() - step1 - step2;

    Summer result = std::for_each(left_border, right_border, Summer());

    std::cout << std::fixed << std::setprecision(10)
              << result.total / result.counter << std::endl;

    return 0;
}