#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "Je suis " << j->getType() << std::endl;
	std::cout << "Je suis " << i->getType() << std::endl;
	std::cout << "Je suis " << wrongCat->getType() << std::endl;

	i->makeSound(); // Cat sound
	j->makeSound(); // Dog sound
	meta->makeSound(); // Generic animal sound

	wrongCat->makeSound(); // WrongCat sound

	delete meta;
	delete j;
	delete i;

	delete wrongCat;

	return 0;
}
