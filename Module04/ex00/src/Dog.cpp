/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:28:05 by hemera            #+#    #+#             */
/*   Updated: 2026/01/22 19:32:12 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") { // Default constructor
	std::cout << " Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) { // Copy constructor
	std::cout << " Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &assign) { // Assignment operator
	if (this != &assign) {
		this->type = assign.type;
	}
	std::cout << " Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog() { // Destructor
	std::cout << " Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}

Animal* newDog() {
	return new Dog();
}
