#include <iostream>
#include <vector>
#include <algorithm>

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
bool is_one_line(Point, Point, Point);
Point get_middle_point(Point, Point, Point);

/*
* Три точки A, B и C, лежат на одной прямой.
* Определите, какая из них лежит между двумя другими. 
*/
int main()
{
    Point a = { "A", 0, 0 };
    Point b = { "B", 0, 0 };
    Point c = { "C", 0, 0 };

    std::cout << "Input coordinates of point A: ";
    std::cin >> a.x >> a.y;
    std::cout << "Input coordinates of point B: ";
    std::cin >> b.x >> b.y;
    std::cout << "Input coordinates of point C: ";
    std::cin >> c.x >> c.y;
    std::cout << std::endl;

    print_coord_point(a);
    print_coord_point(b);
    print_coord_point(c);
    std::cout << std::endl;

    if (!is_one_line(a, b, c)) {
        std::cout << "The points should lie on the same straight line" << std::endl;
        return -1;
    }

    Point middle = get_middle_point(a, b, c);

    std::cout << "The middle point is " << middle.name << "(" << middle.x << ", " << middle.y << ")" << std::endl;

    return 0;
}

void print_coord_point(Point p) {
    std::cout << "Point " << p.name << "(" << p.x << ", " << p.y << ")" << std::endl;
}

bool is_one_line(Point a, Point b, Point c) {
    Vector ab = { "AB", b.x - a.x, b.y - a.y };
    Vector ac = { "AC", c.x - a.x, c.y - a.y };

    return ab.x * ac.y == ac.x * ab.y;
}

Point get_middle_point(Point a, Point b, Point c) {
    if (a.x == b.x || b.x == c.x || a.x == c.x) {
        std::vector<double> v = { a.y, b.y, c.y };
        std::sort(v.begin(), v.end());

        if (v[1] == a.y) {
            return a;
        }
        if (v[1] == b.y) {
            return b;
        }
        if (v[1] == c.y) {
            return c;
        }
    }
    
    std::vector<double> v = { a.x, b.x, c.x };
    std::sort(v.begin(), v.end());

    if (v[1] == a.x) {
        return a;
    }
    if (v[1] == b.x) {
        return b;
    }
    if (v[1] == c.x) {
        return c;
    }
}