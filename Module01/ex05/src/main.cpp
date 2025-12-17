#include "../includes/Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	harl;

	std::cout << "Testing Harl's complaints:" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INVALID");

	return (0);
}
