/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:34:20 by hemera            #+#    #+#             */
/*   Updated: 2026/01/19 21:42:30 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() // Constructeur par défaut
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructed with default values." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // Constructeur avec nom
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) // Constructeur de copie
{
	*this = copy;
	std::cout << "ScavTrap " << this->_name << " copied." << std::endl;
}

ScavTrap::~ScavTrap() // Destructeur
{
	std::cout << "ScavTrap " << this->_name << " destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
	ClapTrap::operator=(assign);
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack." << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode." << std::endl;
}
