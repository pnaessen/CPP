/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:34:10 by pnaessen          #+#    #+#             */
/*   Updated: 2025/04/30 16:29:36 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

void PhoneBook::addContact()  {
	_contact[_index].setContact();
	_index++;
	if(_index % 8 == 0)
		_index = 0;	
}

void PhoneBook::searchContact() {
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	
	for (int i = 0; i < 8; i++) {
		//if (!_contact[i].isEmpty()) {
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
		//}
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}
