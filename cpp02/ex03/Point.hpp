#pragma once
#ifndef __POINT_H__
# define __POINT_H__

# include "Fixed.hpp"

class Point
{

private:
	Fixed const	x;
	Fixed const	y;

public:
	Fixed	getX(void) const;
	Fixed	getY(void) const;

	Point( void );
	Point(float const x, float const y);
	Point(Point const &point);
	Point	&operator=(Point const &rhs);
	~Point( void );
};

std::ostream	&operator<<(std::ostream &o, Point const &rhs);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif