/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:36:11 by hemera            #+#    #+#             */
/*   Updated: 2025/12/08 15:44:31 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

// Setters
void Contact::setFirstname(const std::string& fn)
{ firstname = fn; }

void Contact::setLastname(const std::string& ln)
{ lastname = ln; }

void Contact::setNickname(const std::string& nn)
{ nickname = nn; }

void Contact::setPhoneNumber(const std::string& pn)
{ phoneNumber = pn; }

void Contact::setDarkestSecret(const std::string& ds)
{ darkestSecret = ds; }

// Getters
std::string Contact::getFirstname()
{ return firstname; }

std::string Contact::getLastname()
{ return lastname; }

std::string Contact::getNickname()
{ return nickname; }

std::string Contact::getPhoneNumber()
{ return phoneNumber; }

std::string Contact::getDarkestSecret()
{ return darkestSecret; }
