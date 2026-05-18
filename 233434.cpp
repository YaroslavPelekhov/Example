


template <typename Iter>
typename Iter::value_type process(Iter begin_pos, Iter end_pos,
                                   typename Iter::value_type default_val = typename Iter::value_type()) {
    typedef typename Iter::value_type Elem_Type;
    Elem_Type total_sum = Elem_Type();
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

