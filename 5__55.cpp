



#include <iostream>
#include <string>
#include <stack>

bool is_letter(char ch) {
    return ch >= 'a' && ch <= 'z';
}

bool is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

std::string pop_top(std::stack<std::string>& operand_stack) {
    std::string top_str = operand_stack.top();
    operand_stack.pop();
    return top_str;
}

int main() {
    std::stack<std::string> operand_stack;
    char cur_char;

    while (std::cin >> cur_char) {
        if (is_letter(cur_char)) {
            std::string letter_str(1, cur_char);
            operand_stack.push(letter_str);
            continue;
        }

        if (is_operator(cur_char)) {
            std::string right_str = pop_top(operand_stack);
            std::string left_str = pop_top(operand_stack);
            std::string combined_str = "(" + left_str + cur_char + right_str + ")";
            operand_stack.push(combined_str);
        }
    }

    std::string result_str = operand_stack.top();
    std::cout << result_str << "\n";

    return 0;
}
