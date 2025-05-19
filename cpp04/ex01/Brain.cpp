/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:45:37 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/19 17:23:50 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor call" <<std::endl;

}

Brain::Brain(Brain& obj) {
	std::cout << "Brain copy constructor" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(Brain& obj) {
	std::cout << "Brain copy assignment operator" << std::endl;
	if(this != &obj) {
		for(int i; i < 100; i++) {
			ideas[i] = obj.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor call" <<std::endl;

}