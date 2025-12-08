#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		// Setters
		void setFirstname(const std::string& fn);
		void setLastname(const std::string& ln);
		void setNickname(const std::string& nn);
		void setPhoneNumber(const std::string& pn);
		void setDarkestSecret(const std::string& ds);

		// Getters
		std::string getFirstname();
		std::string getLastname();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif
