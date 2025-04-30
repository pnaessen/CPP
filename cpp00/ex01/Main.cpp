/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 07:52:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/04/30 09:45:21 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
	#include <iostream>
	#include <cstring>

int main()
{
	PhoneBook PhoneBook;
	std::string command;
	
	while (1) {
		std::cout << "Enter a CMD (ADD/SEARCH/EXIT): ";
		std::getline(std::cin, command);
	
		if (std::cin.eof()) {
			break;
		}
		if (command.compare("ADD") == 0) {
			PhoneBook.addContact();
		} 
		 else if (command.compare("SEARCH") == 0) {
		 	PhoneBook.searchContact();
		 } 
		else if (command.compare("EXIT") == 0) {
			break;
		} 
		else {
			std::cout << "Commande invalide.\n";
		}
	}
	return 0;
}


PhoneBook::PhoneBook()
{
	_index = 0;
	std::cout << "PhoneBook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << std::endl <<"PhoneBook destructeur called" << std::endl;
	return ;
}
