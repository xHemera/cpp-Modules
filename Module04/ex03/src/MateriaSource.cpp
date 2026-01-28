/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:08:10 by hemera            #+#    #+#             */
/*   Updated: 2026/01/28 11:08:15 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
    for (int i = 0; i < 4; i++) {
        if (copy._templates[i])
            this->_templates[i] = copy._templates[i]->clone();
        else
            this->_templates[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &assign) {
    if (this != &assign) {
        for (int i = 0; i < 4; i++) {
            if (this->_templates[i])
                delete this->_templates[i];
            this->_templates[i] = NULL;
        }
        for (int i = 0; i < 4; i++) {
            if (assign._templates[i])
                this->_templates[i] = assign._templates[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i])
            delete this->_templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; i++) {
        if (!this->_templates[i]) {
            this->_templates[i] = m->clone();
            delete m;  // On delete l'original, on garde le clone
            return;
        }
    }
    // Slots full
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] && this->_templates[i]->getType() == type)
            return this->_templates[i]->clone();
    }
    return NULL;  // Type inconnu
}
