/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:07:05 by hemera            #+#    #+#             */
/*   Updated: 2026/01/28 11:07:07 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type) {
}

AMateria &AMateria::operator=(const AMateria &assign) {
    // Ne copie PAS le type (selon le sujet)
    (void)assign;
    return *this;
}

AMateria::~AMateria() {
}

std::string const & AMateria::getType() const {
    return this->_type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
    // Fonction vide, sera override par Ice et Cure
}
