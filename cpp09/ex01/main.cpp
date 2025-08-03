/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:21:37 by pn                #+#    #+#             */
/*   Updated: 2025/08/03 21:44:01 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr  << "Error Usage ./RPN \"expression\"" << std::endl;
		return 1;
	}

	try
	{
		RPN test;
		double result = test.;
		std::cout << result << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return (0);
}