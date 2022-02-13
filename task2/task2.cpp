#include <iostream>

struct Point {
    std::string name;
    int x = 0;
    int y = 0;
};

void print_coord_point(Point);
bool is_clockwise_bypass(Point, Point, Point);

/*
* Даны 3 точки A, B и C, не лежащие на одной прямой.
* Определить, является обход A→B→C обходом по часовой стрелке или против часовой стрелки. 
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

    if (is_clockwise_bypass(a, b, c)) {
        std::cout << "A->B->C is a CLOCKWISE bypass" << std::endl;
    }
    else {
        std::cout << "A->B->C is a COUNTERCLOCKWISE bypass" << std::endl;
    }
}

void print_coord_point(Point p) {
    std::cout << "Point " << p.name << "(" << p.x << ", " << p.y << ")" << std::endl;
}

bool is_clockwise_bypass(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) < 0;
}