



#include <iostream>
#include <string>
#include <vector>

bool is_terminal(char ch) {
    bool is_lower = (ch >= 'a' && ch <= 'z');
    bool is_digit = (ch >= '0' && ch <= '9');
    return is_lower || is_digit;
}

bool is_nonterminal(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool is_valid_right_part(const std::string& right_part) {
    if (right_part == "_") {
        return true;
    }
    for (char ch : right_part) {
        bool valid_char = is_terminal(ch) || is_nonterminal(ch);
        if (!valid_char) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::pair<std::string, std::string>> rules;
    std::string left_part, right_part;

    while (std::cin >> left_part >> right_part) {
        rules.push_back({left_part, right_part});
    }

    if (rules.empty()) {
        std::cout << -1 << "\n";
        return 0;
    }

    for (const auto& rule : rules) {
        for (char ch : rule.first) {
            if (!is_nonterminal(ch)) {
                std::cout << -1 << "\n";
                return 0;
            }
        }
        if (!is_valid_right_part(rule.second)) {
            std::cout << -1 << "\n";
            return 0;
        }
    }

    bool has_S_rule = false;
    for (const auto& rule : rules) {
        if (rule.first == "S") {
            has_S_rule = true;
        }
    }
    if (!has_S_rule) {
        std::cout << -1 << "\n";
        return 0;
    }

    bool is_cf = true;
    for (const auto& rule : rules) {
        bool single_nonterm = (rule.first.size() == 1 && is_nonterminal(rule.first[0]));
        if (!single_nonterm) {
            is_cf = false;
            break;
        }
    }

    if (!is_cf) {
        std::cout << 10 << "\n";
        return 0;
    }

    bool has_S_in_right = false;
    for (const auto& rule : rules) {
        if (rule.second == "_") {
            continue;
        }
        for (char ch : rule.second) {
            if (ch == 'S') {
                has_S_in_right = true;
            }
        }
    }

    bool is_non_contracting = true;
    for (const auto& rule : rules) {
        if (rule.second == "_") {
            bool s_rule = (rule.first == "S");
            if (!s_rule || has_S_in_right) {
                is_non_contracting = false;
                break;
            }
        }
    }

    if (is_non_contracting) {
        std::cout << 23 << "\n";
    } else {
        std::cout << 2 << "\n";
    }

    return 0;
}
