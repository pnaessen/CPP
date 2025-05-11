/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:32:00 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/11 10:57:49 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *newZ;
	Zombie *newZ2;
	Zombie *hordeZ;

	newZ = newZombie("BOB");
	newZ->announce();
	newZ2 = newZombie("Heap Z");
	newZ2->announce();
	randomChump("Stack BOBINIO");
	hordeZ = zombieHorde(5, "Gruik");
	delete[] hordeZ;
	delete newZ2;
	delete newZ;
}