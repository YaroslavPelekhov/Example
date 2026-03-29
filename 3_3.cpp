



#include <functional>
#include <vector>

template <typename Iterator, typename Function>
void myapply(Iterator begin_pos, Iterator end_pos, Function func) {
    Iterator cur_pos = begin_pos;
    while (cur_pos != end_pos) {
        func(*cur_pos);
        cur_pos++;
    }
}

template <typename Iterator, typename Predicate>
std::vector<std::reference_wrapper<typename std::iterator_traits<Iterator>::value_type>>
myfilter2(Iterator begin_pos, Iterator end_pos, Predicate condition) {
    typedef typename std::iterator_traits<Iterator>::value_type ElemType;
    typedef std::reference_wrapper<ElemType> RefType;
    typedef std::vector<RefType> VecType;

    VecType answer;
    Iterator cur_pos = begin_pos;

    while (cur_pos != end_pos) {
        if (condition(*cur_pos))
            answer.push_back(std::ref(*cur_pos));
        cur_pos++;
    }

    return answer;
}
