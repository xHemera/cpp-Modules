/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:45 by hemera            #+#    #+#             */
/*   Updated: 2026/01/12 17:46:53 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//		Constructors

Fixed::Fixed()
{
	this->fixed_point_number_value = 0;
	std::cout <<  "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &old_fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = old_fixed;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_number_value = value << this->fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_number_value = roundf(value * (1 << this->fractional_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
//		Overload Operators

Fixed &Fixed::operator=(const Fixed &old_fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this == &old_fixed)
		return *this;
	this->fixed_point_number_value = old_fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed fixed) const
{
	return(this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return(this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return(this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return(this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return(this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return(this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
	return(this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return(this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return(this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return(this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator--()
{
	this->fixed_point_number_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->fixed_point_number_value;
	return (tmp);
}

Fixed	Fixed::operator++()
{
	this->fixed_point_number_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->fixed_point_number_value;
	return (tmp);
}

//		Public Methods

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point_number_value/ (float)(1 << this->fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->fixed_point_number_value >> this->fractional_bits);
}

Fixed			&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed2.toFloat() >= fixed1.toFloat())
		return (fixed1);
	else
		return (fixed2);
}
const Fixed		&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed2.toFloat() >= fixed1.toFloat())
		return (fixed1);
	else
		return (fixed2);
}
Fixed			&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}
const Fixed		&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

//		Getters and Setters
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return  (this->fixed_point_number_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_number_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}
