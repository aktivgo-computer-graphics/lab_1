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
Point get_intersect_point(Point, Point, Point, Point);

/*
* Даны пересекающиеся 2 прямые на плоскости, найти точку их пересечения.
*/
int main()
{
    Point a = { "A", 0, 0 };
    Point c = { "C", 0, 0 };
    Point b = { "B", 0, 0 };
    Point d = { "D", 0, 0 };

    std::cout << "Input coordinates of point A: ";
    std::cin >> a.x >> a.y;
    std::cout << "Input coordinates of point C: ";
    std::cin >> c.x >> c.y;
    std::cout << "Input coordinates of point B: ";
    std::cin >> b.x >> b.y;
    std::cout << "Input coordinates of point D: ";
    std::cin >> d.x >> d.y;
    std::cout << std::endl;

    print_coord_point(a);
    print_coord_point(c);
    print_coord_point(b);
    print_coord_point(d);
    std::cout << std::endl;

    Point p = get_intersect_point(a, c, b, d);
    print_coord_point(p);
    std::cout << std::endl;

    return 0;
}

void print_coord_point(Point p) {
    printf("Point %s(%.4f, %.4f)\n", p.name, p.x, p.y);
}

Point get_intersect_point(Point a, Point c, Point b, Point d) {
    Point p = { "P", 0, 0 };

    p.x = ((c.x - a.x) * (d.x * b.y - b.x * d.y) + (d.x - b.x) * (c.x * a.y - a.x * c.y)) /
        ((c.x - a.x) * (b.y - d.y) - (c.y - a.y) * (b.x - d.x));

    p.y = ((c.y - a.y) * (d.y * b.x - b.y * d.x) + (d.y - b.y) * (c.y * a.x - a.y * c.x)) /
        ((c.y - a.y) * (b.x - d.x) - (c.x - a.x) * (b.y - d.y));

    return p;
}