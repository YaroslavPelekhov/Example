#include <vector>
#include <algorithm>

void process(const std::vector<int>& v1, std::vector<int>& v2) {
    std::vector<int> idx(v1.begin(), v1.end());
    std::sort(idx.begin(), idx.end());
    auto unique_end = std::unique(idx.begin(), idx.end());
    idx.erase(unique_end, idx.end());
    auto valid_end = idx.begin();
    for (auto pos = idx.begin(); pos != idx.end(); ++pos) {
        if (*pos >= 0 && *pos < (int)v2.size()) {
            std::swap(*valid_end, *pos);
            ++valid_end;
        }
    }
    idx.erase(valid_end, idx.end());
    std::sort(idx.begin(), idx.end(), std::greater<int>());
    for (auto pos = idx.begin(); pos != idx.end(); ++pos) {
        v2.erase(v2.begin() + *pos);
    }
}