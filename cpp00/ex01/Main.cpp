/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 07:52:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/10/25 19:30:00 by pnaessen         ###   ########lyon.fr   */
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
			std::cout << "BAD CMD.\n";
		}
		if (std::cin.eof()) {
			break;
		}
	}
	return 0;
}


