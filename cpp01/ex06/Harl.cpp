/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:10:47 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/09 09:41:21 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::warning() {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. /n I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::info() {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::debug() {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::complain(std::string level) {
	
	Harl harl;
	int i;
	
	i = stringToLevel(level);
	switch (i) {
		case 0:
			harl.debug();	
			break;
		case 1:
			harl.info();
			break;
		case 2:
			harl.warning();
			break;
		case 3:
			harl.error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

int stringToLevel(std::string level) {
	int i ;
	
	if (level == "DEBUG")
		i = 0;
	else if (level == "INFO")
		i = 1;
	else if (level == "WARNING")
		i = 2;
	else if (level == "ERROR")
		i = 3;
	else 
		i = 4;
	return i;
}
