



#include <iostream>

/*
 * func(a, b, k):
 * k=0: a + b
 * k=1: a * b
 * k=2: a ^ b
 * k>2: f(a, f(a, b-1, k), k-1)
 */

class Result {
    long long result_val;
public:
    Result(long long result_val) : result_val(result_val) {}
    long long get_result() const { return result_val; }
};

void compute(long long arg_a, long long arg_b, int arg_k) {
    if (arg_k == 0) {
        throw Result(arg_a + arg_b);
    }
    if (arg_b == 1) {
        throw Result(arg_a);
    }
    try {
        compute(arg_a, arg_b - 1, arg_k);
    } catch (const Result& mid_res) {
        compute(arg_a, mid_res.get_result(), arg_k - 1);
    }
}

int main() {
    long long val_a, val_b;
    int val_k;
    while (std::cin >> val_a >> val_b >> val_k) {
        try {
            compute(val_a, val_b, val_k);
        } catch (const Result& final_res) {
            std::cout << final_res.get_result() << '\n';
        }
    }
}
