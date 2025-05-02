/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:53:55 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/02 16:48:15 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


bool Contact::setField(std::string &field, const std::string &prompt) {
	while (1) {
		std::cout << prompt;
		std::getline(std::cin, field);

		if (std::cin.eof()) {
			return(false);
		}

		if (!field.empty()) 
			break;
		std::cout << "Can't be empty.\n";
	}
	return (true);
}

bool Contact::setContact() {
	if(!setField(_firstName, "First name : "))
		return(false);
	if(!setField(_lastName, "Last name : "))
		return(false);
	if(!setField(_nickName, "Nick name : "))
		return(false);
	if(!setField(_phoneNumber, "Phone number : "))
		return(false);
	if(!setField(_darkestSecret, "Darkest secret : "))
		return(false);
	return(true);
}

std::string Contact::getFirstName() const { 
	
	return(_firstName);
}

std::string Contact::getLastName() const { 
	
	return(_lastName);
}

std::string Contact::getNickname() const { 
	
	return(_nickName);
}

bool Contact::isEmpty() { 
	return(_firstName.empty());
}

void Contact::displayDetails() const {
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}

Contact::Contact() {
	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact() {
	std::cout << "Contact destructeur called" << std::endl;
	return ;
}