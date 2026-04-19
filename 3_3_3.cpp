



#include <iostream>
#include <string>

// Язык: a^p 0^q b^p 1^q, p >= 1, q >= 1
// Тип 1 (контекстно-зависимый) — прямая проверка

bool check_word(const std::string& input_word) {
    size_t word_len = input_word.size();
    size_t pos = 0;

    size_t count_a = 0;
    while (pos < word_len && input_word[pos] == 'a') {
        count_a++;
        pos++;
    }

    size_t count_0 = 0;
    while (pos < word_len && input_word[pos] == '0') {
        count_0++;
        pos++;
    }

    size_t count_b = 0;
    while (pos < word_len && input_word[pos] == 'b') {
        count_b++;
        pos++;
    }

    size_t count_1 = 0;
    while (pos < word_len && input_word[pos] == '1') {
        count_1++;
        pos++;
    }

    if (pos != word_len)
        return false;
    if (count_a == 0 || count_0 == 0 || count_b == 0 || count_1 == 0)
        return false;

    return count_a == count_b && count_0 == count_1;
}

int main() {
    std::string input_word;
    while (std::cin >> input_word) {
        if (check_word(input_word)) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }
    return 0;
}
