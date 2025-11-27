#include "../includes/Zombie.hpp"

int main() {
	Zombie* z1 = newZombie("Zombie1");
	z1->announce();
	delete z1;

	randomChump("Zombie2");

	return 0;
}
