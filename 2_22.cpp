



```cpp
#include <iostream>
#include <string>
#include <vector>
#include <set>

bool is_nonterm(char cur_char) {
    return cur_char >= 'A' && cur_char <= 'Z';
}

std::set<char> find_reachable(const std::vector<std::pair<std::string, std::string>>& rules) {
    std::set<char> reachable_set;
    reachable_set.insert('S');

    bool was_changed = true;
    while (was_changed) {
        was_changed = false;
        for (const auto& rule : rules) {
            char left_nonterm = rule.first[0];
            if (reachable_set.count(left_nonterm) == 0) {
                continue;
            }
            for (char cur_char : rule.second) {
                bool is_new_nonterm = is_nonterm(cur_char) && reachable_set.count(cur_char) == 0;
                if (is_new_nonterm) {
                    reachable_set.insert(cur_char);
                    was_changed = true;
                }
            }
        }
    }

    return reachable_set;
}

int main() {
    std::vector<std::pair<std::string, std::string>> rules;
    std::string left_part, right_part;
    while (std::cin >> left_part >> right_part) {
        rules.push_back({left_part, right_part});
    }

    std::set<char> reachable_set = find_reachable(rules);

    for (const auto& rule : rules) {
        char left_nonterm = rule.first[0];
        if (reachable_set.count(left_nonterm) > 0) {
            std::cout << rule.first << " " << rule.second << "\n";
        }
    }

    return 0;
}
```

Только одна функция `find_reachable` вынесена + `is_nonterm`. Чтение и вывод оставил в `main`.
