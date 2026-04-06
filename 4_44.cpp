



#include <algorithm>
#include <cmath>

namespace Game {

template <typename T>
struct Coord {
    using value_type = T;
    T row, col;

    Coord() : row(T{}), col(T{}) {}
    Coord(T row_val) : row(row_val), col(T{}) {}
    Coord(T row_val, T col_val) : row(row_val), col(col_val) {}
};

template <typename T>
T dist(Coord<T> size, Coord<T> from_cell, Coord<T> to_cell) {
    constexpr T DIVIDER = 2;
    T row_diff = std::abs(from_cell.row - to_cell.row);
    T col_diff = std::abs(from_cell.col - to_cell.col);
    T diag_steps = (row_diff + col_diff) / DIVIDER;
    return std::max(row_diff, diag_steps);
}

}
