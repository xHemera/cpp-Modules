/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:47:58 by hemera            #+#    #+#             */
/*   Updated: 2026/01/22 19:32:50 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") { // Default constructor
	std::cout << " WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) { // Copy constructor
	std::cout << " WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &assign) { // Assignment operator
	if (this != &assign) {
		this->type = assign.type;
	}
	std::cout << " WrongCat assignment operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat() { // Destructor
	std::cout << " WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Woem Woem!" << std::endl;
}

WrongAnimal* newWrongCat() {
	return new WrongCat();
}
