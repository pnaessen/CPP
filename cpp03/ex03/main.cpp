/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:43:11 by pn                #+#    #+#             */
/*   Updated: 2025/05/19 08:20:19 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n========== CONSTRUCTEURS ==========\n" << std::endl;
	
	ClapTrap clap("C1");
	std::cout << std::endl;
	
	ScavTrap scav("S1");
	std::cout << std::endl;

	FragTrap frag("F1");
	std::cout << std::endl;

	DiamondTrap diamond("D1");
	std::cout << std::endl;

	
	DiamondTrap diamond_copy(diamond);
	std::cout << std::endl;

	
	DiamondTrap diamond_assign;
	std::cout << std::endl;

	diamond_assign = diamond;
	
	std::cout << "\n========== HERITAGE ==========\n" << std::endl;
	
	std::cout << "--- ClapTrap ---" << std::endl;
	clap.attack("Target");
	
	std::cout << "\n--- ScavTrap ---" << std::endl;
	scav.attack("Target");
	
	std::cout << "\n--- FragTrap ---" << std::endl;
	frag.attack("Target");       
	
	std::cout << "\n--- DiamondTrap ---" << std::endl;
	diamond.attack("Target");
	
	std::cout << "\n========== TEST FONCTIONS  ==========\n" << std::endl;
	
	diamond.takeDamage(30);
	diamond.beRepaired(15);
	
	std::cout << "\n========== FONCTIONS FROM HERITAGE ==========\n" << std::endl;
	
	diamond.guardGate();  
	diamond.highFivesGuys(); 
	
	
	diamond.whoAmI();
	
	std::cout << "\n========== LIMITS TEST ==========\n" << std::endl;
	
	
	diamond.takeDamage(80);
	diamond.attack("Target");
	

	diamond.takeDamage(10);
	diamond.attack("Target");
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	
	ClapTrap* ptr = new DiamondTrap("D2");
	ptr->attack("Target");
	delete ptr;
	std::cout << "\n========== DESTRUCTEURS ==========\n" << std::endl;
	return 0;
}