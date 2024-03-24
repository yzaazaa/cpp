#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedValue = 0;
}

Fixed::Fixed(int const val)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedValue = val << this->nbFractionalBits;
}

Fixed::Fixed(float const val)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedValue = roundf(val * (1 << this->nbFractionalBits));
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedValue = rhs.getRawBits();
	return (*this);
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}


Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
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

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	return o << rhs.toFloat();
}