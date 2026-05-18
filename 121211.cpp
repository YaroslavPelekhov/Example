



#include <iterator>

template <typename Iter, typename T = typename std::iterator_traits<Iter>::value_type>
T process(Iter begin_pos, Iter end_pos, T default_val = T()) {
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
