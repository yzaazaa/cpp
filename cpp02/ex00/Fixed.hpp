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

	Fixed( void );
	Fixed(Fixed const &fixed);
	Fixed	&operator=(Fixed const &rhs);
	~Fixed( void );
};


#endif