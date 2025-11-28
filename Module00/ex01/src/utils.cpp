/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:32:19 by hemera            #+#    #+#             */
/*   Updated: 2025/11/28 14:35:15 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

std::string formatField(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	else if (field.length() < 10)
		return field + std::string(10 - field.length(), ' ') ;
	else
		return field;
}
