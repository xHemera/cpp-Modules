/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:28:05 by hemera            #+#    #+#             */
/*   Updated: 2026/01/28 10:15:13 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") { // Default constructor
	std::cout << "├── Dog constructor" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << "├── Dog copy constructor" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &assign) {
	if (this != &assign) {
		Animal::operator=(assign);
		delete this->brain;
		this->brain = new Brain(*assign.brain);
	}
	std::cout << "├── Dog assignment operator" << std::endl;
	return *this;
}

Dog::~Dog() { // Destructor
	delete this->brain;
	std::cout << "├── Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}
