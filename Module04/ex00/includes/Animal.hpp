/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:24:10 by hemera            #+#    #+#             */
/*   Updated: 2026/01/27 17:02:00 by hemera           ###   ########.fr       */
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

		virtual std::string getType() const;
		virtual void makeSound() const;
		Animal* newAnimal(std::string type);
};



#endif
