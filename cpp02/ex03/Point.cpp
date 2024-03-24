#include "Point.hpp"

Point::Point( void ) : x(0), y(0)
{
	return ;
}

Point::Point(float const x, float const y) : x(Fixed(x)), y(Fixed(y))
{
	return ;
}

Point::Point(Point const &point) :  x(point.getX()), y(point.getY())
{
	return ;
}

Point	&Point::operator=(const Point &rhs)
{
	(Fixed) this->x = rhs.getX();
	(Fixed) this->y = rhs.getY();
	return (*this);
}

Point::~Point( void )
{
	return ;
}

Fixed	Point::getX( void ) const
{
	return (this->x);
}

Fixed	Point::getY( void ) const
{
	return (this->y);
}

std::ostream	&operator<<(std::ostream &o, Point const &rhs)
{
	return (o << "(" << rhs.getX() << ", " << rhs.getY() << ")");
}