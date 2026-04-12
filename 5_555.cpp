



#include <iostream>
#include <chrono>
#include <string>

int main() {
    using namespace std::chrono;

    constexpr int YEAR_LEN = 4;
    constexpr int MONTH_START = 5;
    constexpr int MONTH_LEN = 2;
    constexpr int DAY_START = 8;
    constexpr int DAY_LEN = 2;

    auto parse_date = [&](const std::string& date_input) {
        int year_val = std::stoi(date_input.substr(0, YEAR_LEN));
        int month_val = std::stoi(date_input.substr(MONTH_START, MONTH_LEN));
        int day_val = std::stoi(date_input.substr(DAY_START, DAY_LEN));
        return sys_days(year{year_val} / month{month_val} / day{day_val});
    };

    auto get_diff = [](sys_days date_from, sys_days date_to) {
        long long diff_val = (date_to - date_from).count();
        if (diff_val < 0) {
            diff_val = -diff_val;
        }
        return diff_val;
    };

    std::string input_line;
    long long total_sum = 0;

    if (!std::getline(std::cin, input_line)) {
        std::cout << 0 << "\n";
        return 0;
    }

    sys_days prev_day = parse_date(input_line);

    while (std::getline(std::cin, input_line)) {
        sys_days next_day = parse_date(input_line);
        total_sum += get_diff(prev_day, next_day);
        prev_day = next_day;
    }

    std::cout << total_sum << "\n";
    return 0;
}
