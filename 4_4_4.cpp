



#include <iostream>

// S -> a S d | a B d,  n >= 1
// B -> b B c | b c,    m >= 1

void generate_B(int count_m) {
    std::cout << 'b';
    if (count_m > 1) {
        generate_B(count_m - 1);
    }
    std::cout << 'c';
}

void generate_S(int count_n, int count_m) {
    std::cout << 'a';
    if (count_n > 1) {
        generate_S(count_n - 1, count_m);
    } else {
        generate_B(count_m);
    }
    std::cout << 'd';
}

int main() {
    int input_k;
    std::cin >> input_k;

    if (input_k % 2 != 0) {
        return 0;
    }

    int half_len = input_k / 2;
    for (int count_n = half_len - 1; count_n >= 1; count_n--) {
        int count_m = half_len - count_n;
        generate_S(count_n, count_m);
        std::cout << "\n";
    }

    return 0;
}
