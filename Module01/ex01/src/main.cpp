#include "../includes/Zombie.hpp"
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " <number_of_zombies>" " <name>" << std::endl;
		return 1;
	}

	int N = atoi(argv[1]);
	std::string name = argv[2];

	Zombie* horde = zombieHorde(N, name);

	delete[] horde;

	return 0;
}
