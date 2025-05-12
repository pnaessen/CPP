#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie *newZombie = new Zombie(name);
return newZombie;
}

Zombie* zombieHorde( int N, std::string name ) {
	if(N < 0) {
		std::cout << "Error can't be negative" << std::endl;
		return NULL;
	}
	Zombie *newZombie = new Zombie[N];
	for(int i = 0; i < N; i++) {
		newZombie[i].setName(name);
		newZombie[i].announce();
	}
	return newZombie;
}