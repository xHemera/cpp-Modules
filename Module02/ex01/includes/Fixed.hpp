/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:49 by hemera            #+#    #+#             */
/*   Updated: 2026/01/12 17:46:28 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &old_fixed);
	Fixed(const int value);
	Fixed(const float value);
	Fixed &operator=(const Fixed &old_fixed);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void)	const;
	int		toInt(void)		const;
private:
	int					fixed_point_number_value;
	static const int	fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
