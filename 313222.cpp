



#include <iostream>
#include <list>
#include <deque>
#include <set>
#include <vector>
#include <cstdint>

template <typename Iter, typename T>
T process(Iter begin_pos, Iter end_pos, T default_val) {
    T total_sum = T();
    int odd_count = 0;
    int cur_idx = 0;
    for (Iter cur_pos = begin_pos; cur_pos != end_pos; cur_pos++) {
        if (cur_idx % 2 == 1) {
            total_sum = total_sum + *cur_pos;
            odd_count++;
        }
        cur_idx++;
    }
    if (odd_count == 0) {
        return default_val;
    }
    return total_sum / odd_count;
}

template <typename Iter>
auto process(Iter begin_pos, Iter end_pos) {
    typename Iter::value_type default_val = typename Iter::value_type();
    return process(begin_pos, end_pos, default_val);
}

int main() {
    std::list<int> lst1{1, 2, 4, 5};
    auto res1 = process(lst1.begin(), lst1.end());
    std::cout << "res1 = " << res1 << "\n";

    std::deque<int> deq1{1, 2, 3, 4, 5, 6, 7};
    auto res2 = process(deq1.begin() + 1, deq1.end() - 1);
    std::cout << "res2 = " << res2 << "\n";

    std::set<uint8_t> set1{};
    auto res3 = process(set1.begin(), set1.end());
    std::cout << "res3 = " << (int)res3 << "\n";

    std::vector<double> vec1{1.1};
    auto res4 = process(vec1.begin(), vec1.end(), 100500.0);
    std::cout << "res4 = " << res4 << "\n";

    std::list<int> lst2{1, 2, 4, 5};
    auto res5 = process(lst2.begin(), lst2.end(), 100);
    std::cout << "res5 = " << res5 << "\n";

    return 0;
}
