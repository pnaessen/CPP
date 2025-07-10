/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:57:35 by pn                #+#    #+#             */
/*   Updated: 2025/07/10 10:10:26 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base() {
	
}

Base::Base() {
	
}

Base* generate(void) {
	srand(time(NULL));
	int random = rand() % 3;
	
	switch (random) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return new A();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} 
	else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} 
	else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base& p) {
	
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast&) {}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast&) {}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast&) {}
}