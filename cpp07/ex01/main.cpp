/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:59:08 by pnaessen          #+#    #+#             */
/*   Updated: 2025/09/27 10:19:26 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


void printChar(const char &c) {
	std::cout << c;
}

void toLow(char &c) {
	if(c >= 65 && c <= 90)
	c += 32;
	return ;
}

void inc(int &n) {
	n++;
}

void printInt(const int &c) {
	std::cout << c;
}

void toUpp(char &c) {
	if (c >= 97 && c <= 122)
		c -= 32;
	return ;
}

int main() {
	// char array[] = "test";
	int tab [3] = {1, 2 ,3};
	::iter(tab, 4, toUpp);
	//::iter(tab, 4, printChar);
	// std::cout << std::endl;
	// const int tab_const [3] = {1, 2 ,3};
	// //::iter(tab_const , 3, inc);
	// ::iter(tab_const, 3, printInt);
	// std::cout << std::endl;
	return 0;
}