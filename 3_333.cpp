



#include <iostream>

class S {
    long long num_val;
    bool valid;
public:
    S() : num_val(0), valid(false) {
        if (std::cin >> num_val) {
            valid = true;
        }
    }

    S(S&& other_obj) : num_val(0), valid(false) {
        long long next_val;
        if (std::cin >> next_val) {
            num_val = next_val + other_obj.num_val;
            valid = true;
            other_obj.valid = false;
        }
    }

    S(const S&) = delete;
    S& operator=(const S&) = delete;
    S& operator=(S&&) = delete;

    explicit operator bool() const {
        return valid;
    }

    ~S() {
        if (valid) {
            std::cout << num_val << '\n';
        }
    }
};
