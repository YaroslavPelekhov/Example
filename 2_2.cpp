



template <typename Container, typename Predicate>
Container myfilter(const Container& input_data, Predicate condition) {
    Container result_data;
    auto start_pos = input_data.begin();
    auto finish_pos = input_data.end();

    while (start_pos != finish_pos) {
        if (condition(*start_pos))
            result_data.insert(result_data.end(), *start_pos);
        start_pos++;
    }

    return result_data;
}
