



#include <iostream>
#include <string>
#include <vector>

bool is_nonterm(char cur_char) {
    return cur_char >= 'A' && cur_char <= 'Z';
}

int main() {
    std::vector<std::pair<std::string, std::string>> rules;
    std::string left_part, right_part;
    while (std::cin >> left_part >> right_part) {
        rules.push_back({left_part, right_part});
    }

    bool has_S_in_right = false;
    for (const auto& rule : rules) {
        if (rule.second.find('S') != std::string::npos) {
            has_S_in_right = true;
        }
    }

    bool is_right_lin = true;
    bool is_left_lin = true;
    bool is_right_auto = true;
    bool is_left_auto = true;

    for (const auto& rule : rules) {
        const std::string& right_side = rule.second;

        if (right_side == "_") {
            bool s_eps_ok = (rule.first == "S" && !has_S_in_right);
            if (!s_eps_ok) {
                is_right_lin = false;
                is_left_lin = false;
                is_right_auto = false;
                is_left_auto = false;
            }
            continue;
        }

        int nonterm_count = 0;
        int nonterm_pos = -1;
        for (size_t pos = 0; pos < right_side.size(); pos++) {
            if (is_nonterm(right_side[pos])) {
                nonterm_count++;
                nonterm_pos = pos;
            }
        }

        if (nonterm_count > 1) {
            is_right_lin = false;
            is_left_lin = false;
            is_right_auto = false;
            is_left_auto = false;
            continue;
        }

        if (nonterm_count == 1) {
            bool at_end = (nonterm_pos == (int)right_side.size() - 1);
            bool at_start = (nonterm_pos == 0);
            if (!at_end) {
                is_right_lin = false;
            }
            if (!at_start) {
                is_left_lin = false;
            }
        }

        bool single_term = (right_side.size() == 1 && nonterm_count == 0);
        bool right_auto_pair = (right_side.size() == 2 && nonterm_count == 1 && nonterm_pos == 1);
        bool left_auto_pair = (right_side.size() == 2 && nonterm_count == 1 && nonterm_pos == 0);

        bool right_auto_ok = single_term || right_auto_pair;
        bool left_auto_ok = single_term || left_auto_pair;

        if (!right_auto_ok) {
            is_right_auto = false;
        }
        if (!left_auto_ok) {
            is_left_auto = false;
        }
    }

    if (is_left_lin) {
        if (is_left_auto) {
            std::cout << 311 << "\n";
        } else {
            std::cout << 31 << "\n";
        }
        return 0;
    }

    if (is_right_lin) {
        if (is_right_auto) {
            std::cout << 321 << "\n";
        } else {
            std::cout << 32 << "\n";
        }
        return 0;
    }

    bool is_non_contracting = true;
    for (const auto& rule : rules) {
        if (rule.second == "_") {
            bool s_eps_ok = (rule.first == "S" && !has_S_in_right);
            if (!s_eps_ok) {
                is_non_contracting = false;
                break;
            }
        }
    }

    if (is_non_contracting) {
        std::cout << 21 << "\n";
    } else {
        std::cout << 2 << "\n";
    }

    return 0;
}
