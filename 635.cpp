



#include <iostream>
#include <string>
#include <utility>

std::string input_str;
size_t cur_pos;
char cur_char;
std::string alpha_rev;
int ones_count;

void gc() {
    cur_pos++;
    if (cur_pos < input_str.size()) {
        cur_char = input_str[cur_pos];
    } else {
        cur_char = '\0';
    }
}

bool parse_A() {
    if (cur_char != 'a' && cur_char != 'b') {
        return false;
    }
    while (cur_char == 'a' || cur_char == 'b') {
        alpha_rev = cur_char + alpha_rev;
        gc();
    }
    return true;
}

bool parse_B() {
    while (cur_char == '0' || cur_char == '1') {
        if (cur_char == '1') {
            ones_count++;
        }
        gc();
    }
    return true;
}

std::pair<bool, std::string> transform(const std::string& s) {
    input_str = s;
    cur_pos = 0;
    if (input_str.empty()) {
        cur_char = '\0';
    } else {
        cur_char = input_str[0];
    }
    alpha_rev = "";
    ones_count = 0;

    if (!parse_A()) {
        return {false, ""};
    }
    parse_B();
    if (cur_char != '\0') {
        return {false, ""};
    }

    std::string result_str;
    for (int idx = 0; idx < ones_count; idx++) {
        result_str += 'c';
    }
    result_str += alpha_rev;
    return {true, result_str};
}

void check(const std::string& input, bool expect_ok, const std::string& expect_str) {
    auto result = transform(input);
    std::cout << "input=\"" << input << "\" -> {"
              << (result.first ? "true" : "false") << ", \"" << result.second << "\"}";
    bool ok = (result.first == expect_ok && result.second == expect_str);
    if (ok) {
        std::cout << "  OK\n";
    } else {
        std::cout << "  FAIL (expected {" << (expect_ok ? "true" : "false")
                  << ", \"" << expect_str << "\"})\n";
    }
}

int main() {
    check("abab0110", true, "ccbaba");
    check("a0", true, "a");
    check("a", true, "a");
    check("b", true, "b");
    check("ab", true, "ba");
    check("a1", true, "ca");
    check("a11", true, "cca");
    check("ab10101", true, "cccba");

    check("", false, "");
    check("0110", false, "");
    check("ab10c", false, "");
    check("1ab", false, "");
    check("aXb", false, "");

    return 0;
}
