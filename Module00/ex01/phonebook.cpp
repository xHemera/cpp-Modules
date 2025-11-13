/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:22:55 by hemera            #+#    #+#             */
/*   Updated: 2025/11/13 17:50:41 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static std::string formatField(const std::string& field)
{
	if (field.length() > 9)
		return field.substr(0, 8) + ".";
	else if (field.length() < 9)
		return field + std::string(9 - field.length(), ' ') ;
	else
		return field;
}

int main(void)
{
	PhoneBook phonebook;
	std::string input;
	std::cout << "Welcome to your pretty useless PhoneBook !!" << std::endl;
	while (true)
	{
		std::cout << "> ";
		std::cin >> input;
		if (input == "ADD")
		{
			// Collect contact details
			std::string firstname, lastname, nickname, phoneNumber, darkestSecret;
			std::cout << "Enter firstname :" << std::endl;
			std::cin >> firstname;

			std::cout << "Enter lastname :" << std::endl;
			std::cin >> lastname;

			std::cout << "Enter nickname :" << std::endl;
			std::cin >> nickname;

			std::cout << "Enter phone number :" << std::endl;
			std::cin >> phoneNumber;

			std::cout << "Enter darkest secret :" << std::endl;
			std::cin >> darkestSecret;

			// Create a new contact
			Contact newContact;
			newContact.firstname = firstname;
			newContact.lastname = lastname;
			newContact.nickname = nickname;
			newContact.phoneNumber = phoneNumber;
			newContact.darkestSecret = darkestSecret;

			// Add the new contact to the phonebook and manage overwriting if full
			int prevCount = phonebook.contactCount;
			phonebook.contacts[phonebook.nextIndex] = newContact;
			if (phonebook.contactCount < 8)
				phonebook.contactCount++;
			phonebook.nextIndex = (phonebook.nextIndex + 1) % 8;

			if (prevCount < 8)
				std::cout << "Contact added successfully!" << std::endl;
			else
				std::cout << "PhoneBook full. Oldest contact overwritten." << std::endl;
		}
		else if (input == "SEARCH")
		{
			if (phonebook.contactCount == 0)
			{
					std::cout << "PhoneBook is empty. Please add contacts first." << std::endl;
					continue;
			}

			std::cout << "Index     |Firstname | Lastname | Nickname" << std::endl;

			int i = 0;
			while (i < phonebook.contactCount)
			{
				std::cout << i << "         | "
						  << formatField(phonebook.contacts[i].firstname) << "| "
						  << formatField(phonebook.contacts[i].lastname) << "| "
						  << formatField(phonebook.contacts[i].nickname) << std::endl;
				i++;
			}
		}
		else if (input == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			return 0;
		}
		else {
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		}
	}
	return 0;
}
