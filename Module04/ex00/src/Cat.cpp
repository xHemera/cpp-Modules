/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:29:27 by hemera            #+#    #+#             */
/*   Updated: 2026/01/22 19:32:03 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") { // Default constructor
	std::cout << " Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) { // Copy constructor
	std::cout << " Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &assign) { // Assignment operator
	if (this != &assign) {
		this->type = assign.type;
	}
	std::cout << " Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat() { // Destructor
	std::cout << " Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}

Animal* newCat() {
	return new Cat();
}
