



#include <iostream>
#include <string>

bool check_word(const std::string& input_word) {
    size_t word_len = input_word.size();

    size_t count_k = 0;
    while (count_k < word_len && input_word[count_k] == '0')
        count_k++;

    size_t count_m = 0;
    while (count_k + count_m < word_len && input_word[count_k + count_m] == '1')
        count_m++;

    if (count_k == 0 || count_m == 0)
        return false;

    size_t block_len = count_k + count_m;
    if (word_len % block_len != 0)
        return false;

    size_t num_blocks = word_len / block_len;
    for (size_t block_idx = 1; block_idx < num_blocks; block_idx++) {
        size_t block_start = block_idx * block_len;
        for (size_t pos = 0; pos < block_len; pos++) {
            if (input_word[block_start + pos] != input_word[pos])
                return false;
        }
    }

    return true;
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
