/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:57:31 by pn                #+#    #+#             */
/*   Updated: 2025/07/10 10:16:22 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "Base.hpp"

int main() {
	srand(time(NULL));

	Base* obj1 = generate();
	Base* obj2 = generate();
	Base* obj3 = generate();
	
	std::cout << "Pointer identification:" << std::endl;
	identify(obj1);
	identify(obj2);
	identify(obj3);
	
	std::cout << "\nReference identification:" << std::endl;
	identify(*obj1);
	identify(*obj2);
	identify(*obj3);
	
	delete obj1;
	delete obj2;
	delete obj3;
	
	return 0;
}