



#include <algorithm>

template <typename Iterator, typename Comparator>
void selection_sort(Iterator input_begin, Iterator input_end, Comparator condition) {
    Iterator output_pos = input_begin;
    while (output_pos != input_end) {
        Iterator best_pos = output_pos;
        Iterator input_pos = output_pos;
        input_pos++;
        while (input_pos != input_end) {
            if (condition(*input_pos, *best_pos))
                best_pos = input_pos;
            input_pos++;
        }
        if (best_pos != output_pos)
            std::swap(*output_pos, *best_pos);
        output_pos++;
    }
}

template <typename Iterator>
void selection_sort(Iterator input_begin, Iterator input_end) {
    Iterator output_pos = input_begin;
    while (output_pos != input_end) {
        Iterator best_pos = output_pos;
        Iterator input_pos = output_pos;
        input_pos++;
        while (input_pos != input_end) {
            if (*input_pos < *best_pos)
                best_pos = input_pos;
            input_pos++;
        }
        if (best_pos != output_pos)
            std::swap(*output_pos, *best_pos);
        output_pos++;
    }
}
