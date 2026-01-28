/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:07:45 by hemera            #+#    #+#             */
/*   Updated: 2026/01/28 11:07:46 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(std::string const & name) : _name(name) {
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(const Character &copy) : _name(copy._name) {
    for (int i = 0; i < 4; i++) {
        if (copy._inventory[i])
            this->_inventory[i] = copy._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &assign) {
    if (this != &assign) {
        this->_name = assign._name;
        // Delete old inventory
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i])
                delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
        // Deep copy new inventory
        for (int i = 0; i < 4; i++) {
            if (assign._inventory[i])
                this->_inventory[i] = assign._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            return;
        }
    }
    // Inventory full, do nothing
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
        this->_inventory[idx] = NULL;  // Ne pas delete !
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
        this->_inventory[idx]->use(target);
    }
}
