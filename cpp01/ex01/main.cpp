/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:32:00 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/06 16:10:24 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *newZ;
	Zombie *newZ2;
	Zombie *hordeZ;

	newZ = newZombie("BOB");
	newZ->announce();
	newZ2 = newZombie("YOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
	newZ2->announce();
	randomChump("BOBINIO");
	hordeZ = zombieHorde(50, "Gruik");
	delete newZ2;
	delete newZ;
	delete[] hordeZ;
}