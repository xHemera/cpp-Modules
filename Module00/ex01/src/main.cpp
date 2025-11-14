/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:32:02 by hemera            #+#    #+#             */
/*   Updated: 2025/11/14 12:45:00 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"
#include "../includes/contact.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string input;
	std::cout << "Welcome to your pretty useless PhoneBook !!" << std::endl;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
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
