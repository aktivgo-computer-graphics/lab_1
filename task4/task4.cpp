#include <iostream>

struct Point {
    std::string name;
    double x = 0;
    double y = 0;
};

struct Vector {
    std::string name;
    double x = 0;
    double y = 0;
};

void print_coord_point(Point);
bool is_clockwise_bypass(Point, Point, Point);
bool is_convex_quadrilateral(Point, Point, Point, Point);
bool is_one_line(Point, Point, Point);

/*
* Даны 4 точки A, B, C и D.
* Определить, является ли четырехугольник ABCD выпуклым.
*/
int main()
{
    Point a = { "A", 0, 0 };
    Point b = { "B", 0, 0 };
    Point c = { "C", 0, 0 };
    Point d = { "D", 0, 0 };

    std::cout << "Input coordinates of point A: ";
    std::cin >> a.x >> a.y;
    std::cout << "Input coordinates of point B: ";
    std::cin >> b.x >> b.y;
    std::cout << "Input coordinates of point C: ";
    std::cin >> c.x >> c.y;
    std::cout << "Input coordinates of point D: ";
    std::cin >> d.x >> d.y;
    std::cout << std::endl;

    print_coord_point(a);
    print_coord_point(b);
    print_coord_point(c);
    print_coord_point(d);
    std::cout << std::endl;

    if (is_convex_quadrilateral(a, b, c, d)) {
        std::cout << "The quadrilateral ABCD IS convex" << std::endl;
    }
    else {
        std::cout << "The quadrilateral ABCD IS NOT convex" << std::endl;
    }

    return 0;
}

void print_coord_point(Point p) {
    std::cout << "Point " << p.name << "(" << p.x << ", " << p.y << ")" << std::endl;
}

bool is_clockwise_bypass(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) < 0;
}

bool is_convex_quadrilateral(Point a, Point b, Point c, Point d) {
    bool abc_line = is_one_line(a, b, c);
    bool bcd_line = is_one_line(b, c, d);
    bool cda_line = is_one_line(c, d, a);
    bool dab_line = is_one_line(d, a, b);

    if (abc_line || bcd_line || cda_line || dab_line) {
        return true;
    }

    bool abc_clockwise = is_clockwise_bypass(a, b, c);
    bool bcd_clockwise = is_clockwise_bypass(b, c, d);
    bool cda_clockwise = is_clockwise_bypass(c, d, a);
    bool dab_clockwise = is_clockwise_bypass(d, a, b);

    return abc_clockwise == bcd_clockwise && bcd_clockwise == cda_clockwise && cda_clockwise == dab_clockwise;
}

bool is_one_line(Point a, Point b, Point c) {
    Vector ab = { "AB", b.x - a.x, b.y - a.y };
    Vector ac = { "AC", c.x - a.x, c.y - a.y };

    return ab.x * ac.y == ac.x * ab.y;
}