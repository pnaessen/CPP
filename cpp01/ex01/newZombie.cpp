#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie *newZombie = new Zombie(name);
return newZombie;
}

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *newZombie = new Zombie[N];
	for(int i = 0; i < N; i++) {
		newZombie[i].setName(name);
		newZombie[i].announce();
	}
	return newZombie;
}