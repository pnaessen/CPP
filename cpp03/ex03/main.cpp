/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:43:11 by pn                #+#    #+#             */
/*   Updated: 2025/05/18 18:28:24 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n----- CONSTRUCTEURS -----\n" << std::endl;
	
	ClapTrap clap("C1");
	FragTrap frag("S1");
	
	FragTrap frag_copy(frag);
	
	std::cout << "\n----- TEST FONCTIONS -----\n" << std::endl;
	
	clap.attack("Target"); 
	frag.attack("Target");
	
	clap.takeDamage(5);
	frag.takeDamage(20);
	frag_copy.takeDamage(5);
	
	clap.beRepaired(3);
	frag.beRepaired(10);
	
	std::cout << "\n----- FONCTION GUARD -----\n" << std::endl;
	
	frag.highFivesGuys();
	
	std::cout << "\n----- TEST LIMITS -----\n" << std::endl;
	
	clap.takeDamage(15); 
	clap.attack("Target");
	
	for (int i = 0; i < 10; i++) {
		frag.attack("Dummy");
	}
	
	frag.attack("Target");
	
	std::cout << "\n----- DESTRUCTEURS -----\n" << std::endl;
	
	return 0;
}