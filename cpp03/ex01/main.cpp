/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:43:11 by pn                #+#    #+#             */
/*   Updated: 2025/05/20 14:14:17 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n----- CONSTRUCTEURS -----\n" << std::endl;
	
	ClapTrap clap("C1");
	ScavTrap scav("S1");
	
	ScavTrap scav_copy(scav);
	
	std::cout << "\n----- TEST FONCTIONS -----\n" << std::endl;
	
	clap.attack("Target"); 
	scav.attack("Target");
	
	clap.takeDamage(5);
	scav.takeDamage(20);
	scav_copy.takeDamage(5);
	
	clap.beRepaired(3);
	scav.beRepaired(10);
	
	std::cout << "\n----- FONCTION GUARD -----\n" << std::endl;
	
	scav.guardGate();
	
	std::cout << "\n----- TEST LIMITS -----\n" << std::endl;
	
	clap.takeDamage(15); 
	clap.attack("Target");
	
	for (int i = 0; i < 51; i++) {
		scav.attack("Dummy");
	}
	
	scav.attack("Target");
	ClapTrap* ptr = new ScavTrap("D2");
	ptr->attack("Target");
	delete ptr;
	std::cout << std::endl;
	std::cout << "\n----- DESTRUCTEURS -----\n" << std::endl;

	return 0;
}