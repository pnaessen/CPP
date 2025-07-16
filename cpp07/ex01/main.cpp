/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:59:08 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/16 10:08:00 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void toUpp(char &c) {
	if (c >= 97 && c <= 122)
		c -= 32;
	return ;	
}

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

int main() {
	char array[] = "test";
	::iter(array, 4, toUpp);
	::iter(array, 4, printChar);
	std::cout << std::endl;
	int tab [3] = {1, 2 ,3};
	::iter(tab , 3, inc);
	::iter(tab, 3, printInt);
	std::cout << std::endl;
	return 0;
}