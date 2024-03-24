#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->fixedValue = 0;
}

Fixed::Fixed(int const val)
{
	this->fixedValue = val << this->nbFractionalBits;
}

Fixed::Fixed(float const val)
{
	this->fixedValue = roundf(val * (1 << this->nbFractionalBits));
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	this->fixedValue = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->fixedValue > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->fixedValue < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->fixedValue >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->fixedValue <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->fixedValue == rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++( void )
{
	this->fixedValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	fixed(*this);
	this->fixedValue++;
	return (fixed);
}

Fixed	&Fixed::operator--( void )
{
	this->fixedValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	fixed(*this);
	this->fixedValue--;
	return (fixed);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	return o << rhs.toFloat();
}

Fixed::Fixed(Fixed const &fixed)
{
	*this = fixed;
}


Fixed::~Fixed( void )
{
	return ;
}

int	Fixed::getRawBits( void ) const
{
	return (this->fixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedValue = raw;
}

int	Fixed::toInt( void ) const
{
	return ((int)getRawBits() >> this->nbFractionalBits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)getRawBits() / (1 << this->nbFractionalBits));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}
