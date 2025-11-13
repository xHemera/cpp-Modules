/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:22:55 by hemera            #+#    #+#             */
/*   Updated: 2025/11/14 00:51:52 by hemera           ###   ########.fr       */
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

void add(PhoneBook &phonebook)
{
		std::string firstname, lastname, nickname, phoneNumber, darkestSecret;
		std::cout << "Enter firstname: ";
		while (firstname == "")
		{
			std::cin >> firstname;
			if (std::cin.eof())
				return ;
		}

		std::cout << "Enter lastname: ";
		while (lastname == "")
		{
			std::cin >> lastname;
			if (std::cin.eof())
				return ;
		}

		std::cout << "Enter nickname: ";
		while (nickname == "")
		{
			std::cin >> nickname;
			if (std::cin.eof())
				return ;
		}

		std::cout << "Enter phone number: ";
		while (phoneNumber == "")
		{
			std::cin >> phoneNumber;
			if (std::cin.eof())
				return ;
		}

		std::cout << "Enter darkest secret: ";
		while (darkestSecret == "")
		{
			std::cin >> darkestSecret;
			if (std::cin.eof())
				return ;
		}

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

void search(PhoneBook &phonebook)
{
	if (phonebook.contactCount == 0)
	{
		std::cout << "PhoneBook is empty. Please add contacts first." << std::endl;
		return;
	}

	std::cout << "Index     | Firstname| Lastname | Nickname" << std::endl;
	int i = 0;
	while (i < phonebook.contactCount)
	{
		std::cout << i << "         | "
				  << formatField(phonebook.contacts[i].firstname) << "| "
				  << formatField(phonebook.contacts[i].lastname) << "| "
				  << formatField(phonebook.contacts[i].nickname) << std::endl;
		i++;
	}
	int index;
	while (true)
	{
		std::cout << "Enter the index of the contact to view details: ";
		std::cin >> index;
		if(std::cin.eof())
			break;
		if (index < 0 || index >= phonebook.contactCount)
		{
			std::cout << "Invalid index." << std::endl;
			continue;
		}
		break;
	}
	Contact selectedContact = phonebook.contacts[index];
	std::cout << "Firstname: " << selectedContact.firstname << std::endl;
	std::cout << "Lastname: " << selectedContact.lastname << std::endl;
	std::cout << "Nickname: " << selectedContact.nickname << std::endl;
	std::cout << "Phone Number: " << selectedContact.phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << selectedContact.darkestSecret << std::endl;
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
		if(std::cin.eof())
			break;
		if (input == "ADD")
			add(phonebook);
		else if (input == "SEARCH")
			search(phonebook);
		else if (input == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			return (0);
		}
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
	return 0;
}
