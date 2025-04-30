/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:53:45 by pnaessen          #+#    #+#             */
/*   Updated: 2025/04/30 13:52:30 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
	Contact _contact[8];
	int _index;
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
		
	public:
	PhoneBook(); //constructeur
	~PhoneBook(); //destructeur

	void addContact() ;
	void searchContact();
};