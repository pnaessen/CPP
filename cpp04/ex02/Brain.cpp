/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:45:37 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/21 15:48:16 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor call" <<std::endl;
	std::fill(ideas, ideas + 100, "I like js");
}

Brain::Brain(const Brain& obj) {
	std::cout << "Brain copy constructor" << std::endl;
	for(int i = 0; i < 100; i++) {
		ideas[i] = obj.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& obj) {
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
	if(idx >= 0 && idx < 100) {
		ideas[idx] = idea;
	}
}