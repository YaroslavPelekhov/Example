#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, std::pair<int, int>> students;
    int score;
    std::string surname;
    while (std::cin >> surname >> score) {
       auto& record = students[surname];
       record.first += score;
       record.second++;
    }

    for (auto& student : students) {
        auto& record = student.second;
        double average_score = (double)record.first / record.second;
        std::cout << student.first << " " << average_score << std::endl;
    }

    return 0;
}
