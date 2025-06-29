/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:19:55 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/09 17:18:46 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AScalarConverter.hpp"


int main(int argc, char **argv) {

	if (argc != 2 ) {
		std::cout << "Error: Bad syntax" << std::endl;
		return 1;
	}
	std::string arg1(argv[1]);

	AScalarConverter::convert(arg1);
	return 0;
}


//strtod