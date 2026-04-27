



#include <iostream>
#include <string>
#include <map>
#include <set>

bool make_step(const std::map<std::pair<std::string, char>, std::string>& transitions,
               std::string& state, char cur_char) {
    auto trans_it = transitions.find({state, cur_char});
    if (trans_it == transitions.end()) {
        return false;
    }
    state = trans_it->second;
    return true;
}

int main() {
    std::map<std::pair<std::string, char>, std::string> transitions;
    std::set<std::string> accepting_states;

    std::string cur_state, sym_token, new_state;
    while (std::cin >> cur_state) {
        if (cur_state == "END") {
            break;
        }
        std::cin >> sym_token >> new_state;
        char sym_char = sym_token[0];
        transitions[{cur_state, sym_char}] = new_state;
    }

    std::string accept_state;
    while (std::cin >> accept_state) {
        if (accept_state == "END") {
            break;
        }
        accepting_states.insert(accept_state);
    }

    std::string start_state, input_word;
    std::cin >> start_state >> input_word;

    std::string state = start_state;
    size_t read_count = 0;

    for (size_t pos = 0; pos < input_word.size(); pos++) {
        bool step_ok = make_step(transitions, state, input_word[pos]);
        if (!step_ok) {
            break;
        }
        read_count++;
    }

    bool is_accept = accepting_states.count(state) > 0;

    if (is_accept) {
        std::cout << 1 << "\n";
    } else {
        std::cout << 0 << "\n";
    }
    std::cout << read_count << "\n";
    std::cout << state << "\n";

    return 0;
}
