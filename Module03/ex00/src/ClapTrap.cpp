/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:15:06 by hemera            #+#    #+#             */
/*   Updated: 2026/01/19 21:30:11 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) // Constructeur par défaut
{
	std::cout << "ClapTrap " << this->_name << " constructed with default values." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) // Constructeur avec nom
{
	std::cout << "ClapTrap " << this->_name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) // Constructeur de copie
{
	*this = copy;
	std::cout << "ClapTrap " << this->_name << " copied." << std::endl;
}

ClapTrap::~ClapTrap() // Destructeur
{
    std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack." << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
			  << " points of damage! Remaining hit points: " << this->_hitPoints << std::endl;
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot be repaired." << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired by " << amount
			  << " points! Current hit points: " << this->_hitPoints << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	this->_name = assign._name;
	this->_hitPoints = assign._hitPoints;
	this->_energyPoints = assign._energyPoints;
	this->_attackDamage = assign._attackDamage;
	return *this;
}

