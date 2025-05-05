#include "Zombie.hpp"

void Zombie::announce() {
		std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie* newZombie(std::string name) {
	Zombie *newZombie = new Zombie(name);
return newZombie;
}

Zombie::Zombie (std::string name) {
	_name = name;
	std::cout << "Constructor Zombie name call" << std::endl;
}

void Zombie::randomChump( std::string name) {
	Zombie tmp(name);
	tmp.announce();
}

Zombie::Zombie() {
	
}

Zombie::~Zombie() {
}