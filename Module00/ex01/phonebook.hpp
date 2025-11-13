#include <iostream>
#include <string>

class Contact {
	public:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

class PhoneBook {
	public:
		Contact contacts[8];
		int contactCount;
		int nextIndex;

		PhoneBook() : contactCount(0), nextIndex(0){}
};
