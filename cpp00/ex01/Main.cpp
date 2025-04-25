/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 07:52:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/04/25 09:41:30 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook PhoneBook;

	return (0);
}

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook constructor called" << std::endl;
	this->foo = 42;
	this->i = 5;
	std::cout << "Foo = " << this->foo << " i = " << this->i << std::endl;
	this->test();
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructeur called" << std::endl;
	return ;
}

void PhoneBook::test()
{
	std::cout << "Test function" << std::endl;
}