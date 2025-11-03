/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:43 by pnaessen          #+#    #+#             */
/*   Updated: 2025/11/03 21:18:00 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if(argc < 2) {
		std::cerr << "Usage: " << argv[0] << " 20 9 16 4 8 1 5 17 [...] 32 24 11 13" << std::endl;
		return 1;
	}


	std::vector<std::vector<int> > groups;
	PmergeMe<std::vector<int> > merge;

	try
	{
		merge.processParsing(argc, argv);
		std::cout << "Before: " << merge << std::endl;
		merge.createInitialPairs(groups);

		std::cout << "After merge insert sort\n" << std::endl;
		//printVdeV(groups);
		std::cout << merge << std::endl;

	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}

//./PmergeMe 20 9 16 4 8 1 5 17