



#include <iostream>
#include <string>

class WordFrame {
    std::string text_item;
public:
    WordFrame(const std::string& text_input) : text_item(text_input) {}
    ~WordFrame() {
        std::cout << text_item << std::endl;
    }
};

void read_next() {
    std::string current_word;
    if (!(std::cin >> current_word)) {
        throw "finish";
    }
    WordFrame output_obj(current_word);
    read_next();
}

int main() {
    try {
        read_next();
    } catch (...) {}
    return 0;
}
