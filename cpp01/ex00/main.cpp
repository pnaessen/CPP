/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:32:00 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/06 15:26:08 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *newZ;
	Zombie *newZ2;

	newZ = newZombie("BOB");
	newZ->announce();
	newZ2 = newZombie("YOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
	newZ2->announce();
	randomChump("BOBINIO");
	delete newZ2;
	delete newZ;
}