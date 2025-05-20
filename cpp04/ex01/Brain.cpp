/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:45:37 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/20 13:26:15 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor call" <<std::endl;
	for(int i = 0; i < 100; i++) {
		ideas[i] = "I like js";
	}

}

Brain::Brain(Brain& obj) {
	std::cout << "Brain copy constructor" << std::endl;
	for(int i = 0; i < 100; i++) {
		ideas[i] = obj.ideas[i];
	}
}

Brain& Brain::operator=(Brain& obj) {
	std::cout << "Brain copy assignment operator" << std::endl;
	if(this != &obj) {
		for(int i = 0; i < 100; i++) {
			ideas[i] = obj.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor call" <<std::endl;

}

std::string Brain::getIdeas(int idx) {
	if(idx < 0 || idx > 99) 
		return "Wrong index";
	return ideas[idx];	
}

void Brain::setIdeas(int idx, std::string idea) {
	if(idx >= 0 && idx <= 100) {
		ideas[idx] = idea;
	}
}