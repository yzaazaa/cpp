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
	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

	Fixed( void );
	Fixed(int const val);
	Fixed(float const val);
	Fixed(Fixed const &fixed);
	Fixed	&operator=(Fixed const &rhs);
	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;
	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;
	Fixed	&operator++( void );
	Fixed	operator++(int);
	Fixed	&operator--( void );
	Fixed	operator--(int);
	~Fixed( void );
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
