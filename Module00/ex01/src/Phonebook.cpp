/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:22:55 by hemera            #+#    #+#             */
/*   Updated: 2025/12/08 15:02:45 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0){}

void add(PhoneBook &phonebook)
{
		std::string firstname, lastname, nickname, phoneNumber, darkestSecret;

		while (firstname == "")
		{
			std::cout << "Enter firstname: ";
			std::getline(std::cin, firstname);
			if (std::cin.eof())
				return ;
		}
		while (lastname == "")
		{
			std::cout << "Enter lastname: ";
			std::getline(std::cin, lastname);
			if (std::cin.eof())
				return ;
		}
		while (nickname == "")
		{
			std::cout << "Enter nickname: ";
			std::getline(std::cin, nickname);
			if (std::cin.eof())
				return ;
		}
		while (phoneNumber == "")
		{
			std::cout << "Enter phone number: ";
			std::getline(std::cin, phoneNumber);
			if (std::cin.eof())
				return ;
		}
		while (darkestSecret == "")
		{
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, darkestSecret);
			if (std::cin.eof())
				return ;
		}

	// Create a new contact
	Contact newContact;
	newContact.setFirstname(firstname);
	newContact.setLastname(lastname);
	newContact.setNickname(nickname);
	newContact.setPhoneNumber(phoneNumber);
	newContact.setDarkestSecret(darkestSecret);		// Add the new contact to the phonebook and manage overwriting if full
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

	std::cout << "Index     |Firstname |Lastname  |Nickname" << std::endl;
	int i = 0;
	while (i < phonebook.contactCount)
	{
		std::cout << i << "         |"
				  << formatField(phonebook.contacts[i].getFirstname()) << "|"
				  << formatField(phonebook.contacts[i].getLastname()) << "|"
				  << formatField(phonebook.contacts[i].getNickname()) << std::endl;
		i++;
	}
	int index;
	std::string input;
	while (true)
	{
		std::cout << "Enter the index of the contact to view details: ";
		std::getline(std::cin, input);
		if(std::cin.eof() || std::cin.fail())
			return ;
		std::stringstream ss(input);
		if (!(ss >> index) || !(ss.eof()))
		{
			std::cout << "Invalid input. Please enter a valid index." << std::endl;
			continue;
		}
		if (index < 0 || index >= phonebook.contactCount)
		{
			std::cout << "Invalid index." << std::endl;
			continue;
		}
		break;
	}
	Contact selectedContact = phonebook.contacts[index];
	std::cout << "Firstname: " << selectedContact.getFirstname() << std::endl;
	std::cout << "Lastname: " << selectedContact.getLastname() << std::endl;
	std::cout << "Nickname: " << selectedContact.getNickname() << std::endl;
	std::cout << "Phone Number: " << selectedContact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << selectedContact.getDarkestSecret() << std::endl;
}

