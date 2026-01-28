/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:24:10 by hemera            #+#    #+#             */
/*   Updated: 2026/01/28 10:43:51 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <sstream>

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		Animal &operator=(const Animal &assign);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const = 0;  // Pure virtual function
		Animal* newAnimal(std::string type);
};

#endif
