



#include <iostream>
#include <string>

// S -> 3S | 4S | A
// A -> 1A | 2A | eps

void parse_A(const std::string& input_word, size_t& cur_pos);

void parse_S(const std::string& input_word, size_t& cur_pos) {
    if (cur_pos < input_word.size() && (input_word[cur_pos] == '3' || input_word[cur_pos] == '4')) {
        cur_pos++;
        parse_S(input_word, cur_pos);
    } else {
        parse_A(input_word, cur_pos);
    }
}

void parse_A(const std::string& input_word, size_t& cur_pos) {
    if (cur_pos < input_word.size() && (input_word[cur_pos] == '1' || input_word[cur_pos] == '2')) {
        cur_pos++;
        parse_A(input_word, cur_pos);
    }
}

bool parse_word(const std::string& input_word) {
    size_t cur_pos = 0;
    parse_S(input_word, cur_pos);
    return cur_pos == input_word.size();
}

int main() {
    std::string input_word;
    while (std::cin >> input_word) {
        if (parse_word(input_word)) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }
    return 0;
}
