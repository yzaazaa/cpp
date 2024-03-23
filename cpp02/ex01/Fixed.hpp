#pragma once
# ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>

class Fixed
{

private:
	int					fixedValue;
	static const int	nbFractionalBits = 8;

public:
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed( void );
	Fixed(int const val);
	Fixed(float const val);
	Fixed(Fixed const &fixed);
	Fixed	&operator=(Fixed const &rhs);
	~Fixed( void );
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif