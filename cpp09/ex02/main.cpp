/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:43 by pnaessen          #+#    #+#             */
/*   Updated: 2025/10/23 21:35:18 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if(argc < 2) {
		std::cerr << "Usage: " << argv[0] << " 20 9 16 4 8 1 5 17 [...] 32 24 11 13" << std::endl;
		return 1;
	}

	 PmergeMe<std::vector<int> > merge;

	try
	{
		merge.processParsing(argc, argv);
		std::cout << "Before: " << merge << std::endl;
		merge.mergeInsert();
		std::cout << "After: " << merge << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	//std::lower_bound
	return 0;
}