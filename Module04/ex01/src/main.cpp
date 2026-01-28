#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
	std::cout << "========== Creating array of Animals ==========" << std::endl;
	Animal *animals[4];
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			std::cout << "\n=== Creating Dog " << i << " ===" << std::endl;
			animals[i] = new Dog();
		}
		else {
			std::cout << "\n=== Creating Cat " << i << " ===" << std::endl;
			animals[i] = new Cat();
		}
	}

	// std::cout << "\n========== Testing deep copy ==========" << std::endl;
	// std::cout << "\n=== Creating Dog basic ===" << std::endl;
	// Dog basic;
	// {
	// 	std::cout << "\n=== Creating Dog tmp as copy ===" << std::endl;
	// 	Dog tmp = basic;
	// 	std::cout << "\n=== tmp going out of scope ===" << std::endl;
	// }
	// std::cout << "\n=== basic still exists (no crash = deep copy works) ===" << std::endl;

	std::cout << "\n========== Deleting all animals ==========" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "\n=== Deleting Animal " << i << " ===" << std::endl;
		delete animals[i];
	}
	return 0;
}
