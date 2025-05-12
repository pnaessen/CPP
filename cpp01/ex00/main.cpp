/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:32:00 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/12 12:43:43 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *newZ;
	Zombie *newZ2;

	newZ = newZombie("BOB");
	newZ->announce();
	newZ2 = newZombie("Heap Z");
	newZ2->announce();
	randomChump("Stack BOBINIO");
	delete newZ2;
	delete newZ;
}