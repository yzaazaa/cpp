#include "Point.hpp"

int main ( void )
{
    Point   a(0, 0);
    Point   b(1, 0);
    Point   c(0, 1);
    Point   point(0.5, 0);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "point: " << point << std::endl;
    if (bsp(a, b, c, point))
        std::cout << "Point is in the triangle" << std::endl;
    else
        std::cout << "Point is not in the triangle" << std::endl;
    return 0;
}