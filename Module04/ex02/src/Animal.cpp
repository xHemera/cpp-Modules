/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:33:12 by hemera            #+#    #+#             */
/*   Updated: 2026/01/27 14:24:21 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &assign) {
	if (this != &assign) {
		this->type = assign.type;
	}
	std::cout << " Animal assignment operator called" << std::endl;
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "Generic animal sound" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}
