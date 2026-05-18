





#include <iostream>
#include <utility>

class SharedInt {
public:
    SharedInt(int input_val = 0) {
        value_ptr = new int(input_val);
        ref_count = new int(1);
    }

    SharedInt(const SharedInt& other) {
        value_ptr = other.value_ptr;
        ref_count = other.ref_count;
        (*ref_count)++;
    }

    SharedInt(SharedInt&& other) {
        value_ptr = other.value_ptr;
        ref_count = other.ref_count;
        other.value_ptr = new int(0);
        other.ref_count = new int(1);
    }

    ~SharedInt() {
        (*ref_count)--;
        if (*ref_count == 0) {
            delete value_ptr;
            delete ref_count;
        }
    }

    SharedInt& operator=(SharedInt other) {
        swap(other);
        return *this;
    }

    SharedInt& operator+=(const SharedInt& other) {
        *value_ptr += *other.value_ptr;
        return *this;
    }

    SharedInt operator+(const SharedInt& other) const {
        return SharedInt(*value_ptr + *other.value_ptr);
    }

    SharedInt& operator++() {
        (*value_ptr)++;
        return *this;
    }

    SharedInt operator++(int) {
        SharedInt old_copy(*value_ptr);
        (*value_ptr)++;
        return old_copy;
    }

    SharedInt operator-() const {
        return SharedInt(-(*value_ptr));
    }

    operator bool() const {
        return *value_ptr != 0;
    }

    int value() const {
        return *value_ptr;
    }

    SharedInt clone() const {
        return SharedInt(*value_ptr);
    }

private:
    int* value_ptr;
    int* ref_count;

    void swap(SharedInt& other) {
        int* tmp_val = value_ptr;
        int* tmp_cnt = ref_count;
        value_ptr = other.value_ptr;
        ref_count = other.ref_count;
        other.value_ptr = tmp_val;
        other.ref_count = tmp_cnt;
    }
};

int main() {
    SharedInt a;
    SharedInt b(a);
    SharedInt c(100);
    std::cout << "a=" << a.value() << " b=" << b.value() << " c=" << c.value() << "\n";

    int v = (c++).value();
    std::cout << "v=" << v << " c=" << c.value() << "\n";

    c = b;
    std::cout << "after c=b: c=" << c.value() << "\n";

    SharedInt d(std::move(b));
    std::cout << "d=" << d.value() << " b=" << b.value() << "\n";

    auto e = d.clone();
    std::cout << "e=" << e.value() << "\n";

    SharedInt x(5);
    SharedInt y(3);
    SharedInt z = x + y;
    std::cout << "5+3 = " << z.value() << "\n";

    x += y;
    std::cout << "x+=y: x=" << x.value() << "\n";

    ++z;
    std::cout << "++z: z=" << z.value() << "\n";

    SharedInt neg = -x;
    std::cout << "-x = " << neg.value() << "\n";

    SharedInt zero(0);
    if (zero) {
        std::cout << "zero is true\n";
    } else {
        std::cout << "zero is false\n";
    }
    if (x) {
        std::cout << "x is true\n";
    }

    return 0;
}
