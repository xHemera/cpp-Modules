/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:37:57 by hemera            #+#    #+#             */
/*   Updated: 2026/01/28 10:15:12 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "└─── Brain constructor" << std::endl;
}

Brain::Brain(const Brain &copy) {
	std::cout << "└─── Brain copy constructor" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = copy.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &assign) {
	if (this != &assign) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = assign.ideas[i];
		}
	}
	std::cout << "└─── Brain assignment operator" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "┌─── Brain destructor called" << std::endl;
}
