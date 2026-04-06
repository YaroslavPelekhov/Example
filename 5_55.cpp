



class Figure {
public:
    virtual bool equals(const Figure* other_figure) const = 0;
    virtual ~Figure() = default;
};

class Rectangle : public Figure {
    int width, height;
public:
    Rectangle(int width, int height) : width(width), height(height) {}

    bool equals(const Figure* other_figure) const override {
        const Rectangle* other_rect = dynamic_cast<const Rectangle*>(other_figure);
        if (other_rect == nullptr)
            return false;
        bool same_width = (width == other_rect->width);
        bool same_height = (height == other_rect->height);
        return same_width && same_height;
    }
};

class Triangle : public Figure {
    int side_a, side_b, side_c;
public:
    Triangle(int side_a, int side_b, int side_c)
        : side_a(side_a), side_b(side_b), side_c(side_c) {}

    bool equals(const Figure* other_figure) const override {
        const Triangle* other_tri = dynamic_cast<const Triangle*>(other_figure);
        if (other_tri == nullptr)
            return false;
        bool same_a = (side_a == other_tri->side_a);
        bool same_b = (side_b == other_tri->side_b);
        bool same_c = (side_c == other_tri->side_c);
        return same_a && same_b && same_c;
    }
};
