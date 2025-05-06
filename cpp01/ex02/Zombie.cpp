#include "Zombie.hpp"

void Zombie::announce() {
		std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::Zombie (std::string name) {
	_name = name;
	std::cout << "Constructor Zombie name call" << std::endl;
}

Zombie::Zombie() {
	std::cout << "Constructor Zombie" << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " deconstructor call" << std::endl;

}

void Zombie::setName(std::string name) {
	_name = name;
}