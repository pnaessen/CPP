/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:23:39 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/01 17:18:00 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


class Contact {
	private: 
	std::string _firstName; //attributs
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
	bool setField(std::string &field, const std::string &prompt);

	public:
	std::string getFirstName()const ;
	std::string getLastName()const ;
	std::string getNickname()const ;
	bool isEmpty();
	bool setContact();
	void displayDetails() const;
};