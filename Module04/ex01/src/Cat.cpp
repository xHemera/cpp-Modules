/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:29:27 by hemera            #+#    #+#             */
/*   Updated: 2026/01/28 10:15:14 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") { // Default constructor
	std::cout << "├── Cat constructor" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "├── Cat copy constructor" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &assign) {
	if (this != &assign) {
		Animal::operator=(assign);
		delete this->brain;
		this->brain = new Brain(*assign.brain);
	}
	std::cout << "├── Cat assignment operator" << std::endl;
	return *this;
}

Cat::~Cat() { // Destructor
	delete this->brain;
	std::cout << "├── Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}
