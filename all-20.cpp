#include <vector>

void process(const std::vector<unsigned long long>& first, 
             std::vector<unsigned long long>& second, 
             int step) {
    int i = 0;
    auto pos = second.end();
    for (auto& val : first) {
        if (i % step == 0) {
            if (pos == second.begin()) break;
            --pos;
            *pos += val;
        }
        i++;
    }
}