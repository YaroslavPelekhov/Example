#include <iostream>
#include <utility>
#include <map>

enum { MOD = 4294967161ULL };

int main() {
    std::map<std::pair<unsigned, unsigned>, unsigned long long> matrix;

    unsigned row, col;
    unsigned long long val;

    while (std::cin >> row >> col >> val) {
        if (row == 0 && col == 0 && val == MOD) {
            break;
        }
        matrix[{row, col}] += val;
        matrix[{row, col}] %= MOD;
    }

    while (std::cin >> row >> col >> val) {
        matrix[{row, col}] += val;
        matrix[{row, col}] %= MOD;
    }

    for (const auto& elem : matrix) {
    const std::pair<unsigned, unsigned>& pos = elem.first;

    if (elem.second != 0) {
        std::cout << pos.first << " " << pos.second << " " << elem.second << std::endl;
    }
}

    return 0;
}
