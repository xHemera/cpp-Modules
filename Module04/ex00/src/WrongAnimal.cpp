/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:53:47 by hemera            #+#    #+#             */
/*   Updated: 2026/01/22 19:32:30 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << " WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << " WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type) {
	std::cout << " WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign) {
	if (this != &assign) {
		this->type = assign.type;
	}
	std::cout << " WrongAnimal assignment operator called" << std::endl;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Generic WrongAnimal sound" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << " WrongAnimal destructor called" << std::endl;
}

WrongAnimal* newWrongCat();

WrongAnimal* newWrongAnimal(std::string type) {
	if (type == "Cat") {
		return newWrongCat();
	} else {
		return 0;
	}
}
