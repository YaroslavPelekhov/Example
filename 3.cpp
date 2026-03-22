#include <iostream>
#include <iomanip>
#include <map>
#include <set>

enum { 
    WIDTH = 2,
    DECIMAL_BASE = 10
};

struct Date {
    int year, month, day;

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

std::istream& operator>>(std::istream& input, Date& d) {
    char sep1, sep2;
    input >> d.year >> sep1 >> d.month >> sep2 >> d.day;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Date& d) {
    output << d.year << "/";

    if (d.month < DECIMAL_BASE) output << "0";
    output << d.month << "/";

    if (d.day < DECIMAL_BASE) output << "0";
    output << d.day;

    return output;
}

int main() {
    std::map<std::string, std::map<Date, int>> marks;
    std::set<Date> all_dates;
    int mark;
    std::string surname;
    Date current_date;

    while (std::cin >> surname >> current_date >> mark) {
        marks[surname][current_date] = mark;
        all_dates.insert(current_date);
    }

    std::cout << ".";
    for (const auto& date : all_dates) {
        std::cout << "\t" << date;
    }
    std::cout << std::endl;

    for (const auto& student : marks) {
        std::cout << student.first;
        for (const auto& date : all_dates) {
            std::cout << "\t";
            std::map<Date, int>::const_iterator pos = student.second.find(date);
            if (pos == student.second.end()) {
                std::cout << ".";
            } else {
                std::cout << pos->second;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
