#include <iostream>
#include <utility>
#include <map>

enum { MOD = 4294967161ULL };

int main() {
    std::map<std::pair<unsigned, unsigned>, unsigned long long> matrix1;
    std::map<std::pair<unsigned, unsigned>, unsigned long long> matrix2;
    std::map<std::pair<unsigned, unsigned>, unsigned long long> result;

    unsigned row, col;
    unsigned long long val;

    while (std::cin >> row >> col >> val) {
        if (row == 0 && col == 0 && val == MOD) {
            break;
        }
        matrix1[{row, col}] = val;
    }

    while (std::cin >> row >> col >> val) {
        matrix2[{row, col}] = val;
    }

    for (const auto& elem1 : matrix1) {
        unsigned row1 = elem1.first.first;
        unsigned col1 = elem1.first.second;
        unsigned long long val1 = elem1.second;

        for (const auto& elem2 : matrix2) {
            unsigned row2 = elem2.first.first;
            unsigned col2 = elem2.first.second;
            unsigned long long val2 = elem2.second;

            if (col1 == row2) {
                result[{row1, col2}] += (val1 * val2) % MOD;
                result[{row1, col2}] %= MOD;
            }
        }
    }

    for (const auto& elem : result) {
        const std::pair<unsigned, unsigned>& pos = elem.first;

        if (elem.second != 0) {
            std::cout << pos.first << " " << pos.second << " " << elem.second << std::endl;
        }
    }

    return 0;
}
