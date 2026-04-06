



#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <memory>
#include <numbers>

class Figure {
public:
    virtual double get_square() const = 0;
    virtual std::string to_string() const = 0;
    virtual ~Figure() = default;
};

class Rectangle : public Figure {
    double width, height;
    Rectangle(double width, double height) : width(width), height(height) {}
public:
    double get_square() const override { return width * height; }
    std::string to_string() const override {
        return "R " + std::to_string(width) + " " + std::to_string(height);
    }
    static Figure* make(const std::string& input) {
        std::istringstream stream(input);
        double w, h;
        stream >> w >> h;
        return new Rectangle(w, h);
    }
};

class Square : public Figure {
    double side;
    Square(double side) : side(side) {}
public:
    double get_square() const override { return side * side; }
    std::string to_string() const override {
        return "S " + std::to_string(side);
    }
    static Figure* make(const std::string& input) {
        std::istringstream stream(input);
        double s;
        stream >> s;
        return new Square(s);
    }
};

class Circle : public Figure {
    double radius;
    Circle(double radius) : radius(radius) {}
public:
    double get_square() const override { return std::numbers::pi * radius * radius; }
    std::string to_string() const override {
        return "C " + std::to_string(radius);
    }
    static Figure* make(const std::string& input) {
        std::istringstream stream(input);
        double r;
        stream >> r;
        return new Circle(r);
    }
};

class Factory {
    std::map<std::string, std::function<Figure*(const std::string&)>> builder_map;

    Factory() {
        builder_map["R"] = Rectangle::make;
        builder_map["S"] = Square::make;
        builder_map["C"] = Circle::make;
    }
public:
    static Factory& factory_instance() {
        static Factory singleton;
        return singleton;
    }

    Figure* create(const std::string& figure_type, const std::string& figure_params) {
        return builder_map.at(figure_type)(figure_params);
    }
};

int main() {
    std::vector<std::unique_ptr<Figure>> figure_list;
    std::string input_line;

    while (std::getline(std::cin, input_line)) {
        std::istringstream input_stream(input_line);
        std::string figure_type, figure_params;
        input_stream >> figure_type;
        std::getline(input_stream, figure_params);
        figure_list.emplace_back(
            Factory::factory_instance().create(figure_type, figure_params)
        );
    }

    std::stable_sort(figure_list.begin(), figure_list.end(),
        [](const auto& lhs, const auto& rhs) {
            return lhs->get_square() < rhs->get_square();
        });

    for (const auto& fig : figure_list)
        std::cout << fig->to_string() << "\n";

    return 0;
}
