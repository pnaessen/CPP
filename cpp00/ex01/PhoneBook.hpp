/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:53:45 by pnaessen          #+#    #+#             */
/*   Updated: 2025/04/25 14:10:34 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
	Contact contact[8];
	int index;
		
	public:
	PhoneBook(); //constructeur
	~PhoneBook(); //destructeur
	void test();
	int foo;
	int i;

	void addContact();
	void searchContact();
};