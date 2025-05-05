#include <iostream>
#include <string>
#include <new> 


class Zombie{
	private:
	std::string _name;

	public:
	void announce();
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void randomChump( std::string name );
};

Zombie* newZombie(std::string name);
