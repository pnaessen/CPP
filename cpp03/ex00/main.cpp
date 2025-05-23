/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:43:11 by pn                #+#    #+#             */
/*   Updated: 2025/05/20 14:10:36 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "\n----- CONSTRUCTEURS -----\n" << std::endl;

	std::string name = "RIKO";
	ClapTrap claptrap1(name);
	ClapTrap claptrap2;
	ClapTrap claptrap3(claptrap1);
	ClapTrap claptrap4;
	
	std::cout << "\n----- TEST FONCTIONS -----\n" << std::endl;

	claptrap1.attack("Bandit");
	claptrap1.takeDamage(3);
	claptrap1.beRepaired(-2);
	claptrap4 = claptrap1;
	claptrap4.beRepaired(2);
	
	std::cout << "\n----- TEST LIMITS -----\n" << std::endl;

	for (int i = 0; i < 10; i++) {
		claptrap2.attack("Target");
	}
	claptrap2.attack("Target");
	claptrap2.beRepaired(4);
	claptrap3.takeDamage(-15); 
	claptrap3.attack("Target");
	
	return (0);
}