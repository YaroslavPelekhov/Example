



#include <iostream>
#include <string>

std::string input_expr;
size_t cur_pos;
char cur_char;

void gc() {
    cur_pos++;
    if (cur_pos < input_expr.size()) {
        cur_char = input_expr[cur_pos];
    } else {
        cur_char = '\0';
    }
}

int parse_level(int level, std::string& out_str);

int parse_P(std::string& out_str) {
    if (cur_char == '(') {
        gc();
        int inner_prio = parse_level(5, out_str);
        gc();
        return inner_prio;
    }
    out_str = std::string(1, cur_char);
    gc();
    return 0;
}

bool match_level(char op_char, int level) {
    if (level == 1) return op_char == '*' || op_char == '/';
    if (level == 2) return op_char == '+' || op_char == '-';
    if (level == 3) return op_char == '&';
    if (level == 4) return op_char == '^';
    if (level == 5) return op_char == '|';
    return false;
}

int parse_level(int level, std::string& out_str) {
    if (level == 0) {
        return parse_P(out_str);
    }

    std::string left_str;
    int left_prio = parse_level(level - 1, left_str);

    bool found_op = false;
    while (match_level(cur_char, level)) {
        found_op = true;
        char op_char = cur_char;
        gc();

        std::string right_str;
        int right_prio = parse_level(level - 1, right_str);

        std::string wrapped_right = right_str;
        if (right_prio >= level) {
            wrapped_right = "(" + right_str + ")";
        }

        left_str = left_str + op_char + wrapped_right;
    }

    out_str = left_str;
    if (found_op) {
        return level;
    }
    return left_prio;
}

int main() {
    std::getline(std::cin, input_expr);
    cur_pos = 0;
    if (input_expr.empty()) {
        cur_char = '\0';
    } else {
        cur_char = input_expr[0];
    }

    std::string result_str;
    parse_level(5, result_str);

    std::cout << result_str << "\n";
    return 0;
}
