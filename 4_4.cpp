



#include <algorithm>
#include <vector>

template <typename IndexIterator, typename ElemIterator>
ElemIterator myremove(IndexIterator idx_start, IndexIterator idx_end,
                      ElemIterator elem_start, ElemIterator elem_end) {
    std::vector<int> index_list;
    IndexIterator index_cur = idx_start;
    while (index_cur != idx_end) {
        index_list.push_back(*index_cur);
        index_cur++;
    }

    std::sort(index_list.begin(), index_list.end());
    auto duplicate_border = std::unique(index_list.begin(), index_list.end());
    index_list.erase(duplicate_border, index_list.end());

    int total_count = 0;
    ElemIterator count_cur = elem_start;
    while (count_cur != elem_end) {
        total_count++;
        count_cur++;
    }

    std::vector<bool> drop_flag(total_count, false);
    for (auto index_pos = index_list.begin(); index_pos != index_list.end(); index_pos++) {
        int index_val = *index_pos;
        if (index_val >= 0 && index_val < total_count)
            drop_flag[index_val] = true;
    }

    ElemIterator write_cur = elem_start;
    ElemIterator read_cur = elem_start;
    int current_offset = 0;
    while (read_cur != elem_end) {
        if (!drop_flag[current_offset]) {
            *write_cur = std::move(*read_cur);
            write_cur++;
        }
        read_cur++;
        current_offset++;
    }

    return write_cur;
}
