/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:34:10 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/05 08:36:56 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

void PhoneBook::addContact()  {
	_contact[_index].setContact();
	_index++;
	if(_index % 8 == 0)
		_index = 0;	
}

PhoneBook::PhoneBook()
{
	_index = 0;
	std::cout << "PhoneBook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout <<"PhoneBook destructeur called" << std::endl;
	return ;
}

void PhoneBook::searchContact() {
	if(_contact[0].isEmpty()) {
		std::cout << "ADD a user first" << std::endl;
		return ;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	
	for (int i = 0; i < 8; i++) {
		if (!_contact[i].isEmpty()) {
			std::cout << "|" << std::setw(10) << i + 1 << "|";
			std::string firstName = _contact[i].getFirstName();
			if (firstName.length() > 10)
				std::cout << firstName.substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << firstName << "|";
			std::string lastName = _contact[i].getLastName();
			if (lastName.length() > 10)
				std::cout << lastName.substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << lastName << "|";
			std::string nickname = _contact[i].getNickname();
			if (nickname.length() > 10)
				std::cout << nickname.substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << nickname << "|";
			
			std::cout << std::endl;
		}
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	
	std::cout << "Select an index : ";
	std::string input;
	while(std::getline(std::cin, input))
	{
		if (std::cin.eof()) {
			std::cout << std::endl;
			return;
		}
		std::stringstream ss(input);
		int index;
		if (!(ss >> index) || index < 1 || index > 8 || _contact[index - 1].isEmpty()) {
			std::cout << "Invalid index." << std::endl;
			std::cout << "Select an index : ";
		}
		else {
			_contact[index - 1].displayDetails();
			return;
		}
	}
}
