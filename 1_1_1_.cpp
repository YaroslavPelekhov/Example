



#include <iostream>
#include <string>

bool check_word(const std::string& input_word) {
    size_t word_len = input_word.size();

    size_t count_alpha = 0;
    while (count_alpha < word_len && (input_word[count_alpha] == '3' || input_word[count_alpha] == '4'))
        count_alpha++;

    size_t count_beta = 0;
    while (count_alpha + count_beta < word_len && (input_word[count_alpha + count_beta] == '1' || input_word[count_alpha + count_beta] == '2'))
        count_beta++;

    return count_alpha + count_beta == word_len;
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
