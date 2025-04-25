/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:53:45 by pnaessen          #+#    #+#             */
/*   Updated: 2025/04/25 12:26:39 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	public:
	PhoneBook(); //constructeur
	~PhoneBook(); //destructeur
	void test();
	int foo;
	int i;
	   void setContact(std::string &firstName,
	   			std::string &lastName, std::string &nickname,std::string &phoneNumber,
				std::string &darkestSecret);
				
};