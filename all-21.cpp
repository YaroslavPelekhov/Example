#include <vector>

void process(std::vector<long long>& nums, long long limit) {
    size_t original_size = nums.size();
    size_t count = 0;
    for (auto& val : nums) {
        if (val >= limit) count++;
    }
    nums.reserve(original_size + count);
    for (auto pos = nums.begin() + original_size - 1; pos >= nums.begin(); --pos) {
        if (*pos >= limit) {
            nums.push_back(*pos);
        }
    }
}