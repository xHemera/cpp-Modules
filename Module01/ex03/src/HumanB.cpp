/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:14:46 by hemera            #+#    #+#             */
/*   Updated: 2025/12/12 13:36:57 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string humanName) : name(humanName), weapon(NULL) {};

HumanB::~HumanB() {};

void HumanB::setWeapon(Weapon& humanWeapon) {
	this->weapon = &humanWeapon;
}

void HumanB::attack() {
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with his bare hands (which isn't very effective)" << std::endl;
}
