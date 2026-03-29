



#include <iterator>

template <typename Container>
typename Container::value_type process(const Container& input_data) {
    enum { STEP_SIZE = 2 };

    if (input_data.empty())
        return typename Container::value_type{};

    typename Container::value_type total_elem = {};

    auto shift_left = [](typename Container::const_iterator& current_pos,
                         typename Container::const_iterator start_pos,
                         int step_count) {
        for (int step_idx = 0; step_idx < step_count; step_idx++) {
            if (current_pos == start_pos) return false;
            current_pos--;
        }
        return true;
    };

    auto current_pos = input_data.end();
    shift_left(current_pos, input_data.begin(), 1);
    total_elem += *current_pos;

    if (shift_left(current_pos, input_data.begin(), STEP_SIZE))
        total_elem += *current_pos;

    if (shift_left(current_pos, input_data.begin(), STEP_SIZE))
        total_elem += *current_pos;

    return total_elem;
}
