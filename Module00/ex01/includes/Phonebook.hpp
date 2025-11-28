#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"

class PhoneBook {
	public:
		Contact contacts[8];
		int contactCount;
		int nextIndex;

		PhoneBook();
};

void add(PhoneBook &phonebook);
void search(PhoneBook &phonebook);
std::string formatField(const std::string& field);

#endif
