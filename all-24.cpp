#include <iostream>
#include <list>

std::list<int>::iterator find_position(std::list<int>& list_data, int target_pos) {
    auto position = list_data.begin();
    int current = 1;
    while (position != list_data.end() && current < target_pos) {
        ++position;
        ++current;
    }
    return position;
}

int main() {
    std::list<int> list_data;

    int number;
    while (std::cin >> number && number != 0) {
        list_data.push_back(number);
    }

    int first_cmd;
    while (std::cin >> first_cmd) {
        if (first_cmd < 0) {
            int target_pos = -first_cmd;
            auto position = find_position(list_data, target_pos);
            if (position != list_data.end()) {
                list_data.erase(position);
            }
        } else {
            int insert_value;
            std::cin >> insert_value;
            auto position = find_position(list_data, first_cmd);
            list_data.insert(position, insert_value);
        }
    }

    for (auto position = list_data.begin(); position != list_data.end(); ++position) {
        std::cout << *position << "\n";
    }

    list_data.clear();
    return 0;
}