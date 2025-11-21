/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:21:37 by pn                #+#    #+#             */
/*   Updated: 2025/11/21 13:07:36 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr  << "Error Usage ./RPN \"expression\"" << std::endl;
		return 1;
	}

	std::string expression = argv[1];
	try
	{
		RPN test;
		int result = test.process(expression);
		std::cout << result << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return (0);
}