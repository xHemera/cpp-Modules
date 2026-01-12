/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:45 by hemera            #+#    #+#             */
/*   Updated: 2026/01/12 17:45:56 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed &Fixed::operator=(const Fixed &old_fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this == &old_fixed)
		return *this;
	this->fixed_point_number_value = old_fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

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
