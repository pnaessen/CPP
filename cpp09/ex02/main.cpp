/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:43 by pnaessen          #+#    #+#             */
/*   Updated: 2025/10/30 16:10:57 by pnaessen         ###   ########lyon.fr   */
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
		//std::cout << "after createInitialPairs\n" << std::endl;
		//printVdeV(groups);
		// std::cout << "After: " << merge << std::endl;
		std::cout << "Call merge insert sort\n" << std::endl;
		mergeInsertSort(groups);
		//printVdeV(groups);

	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	//std::lower_bound
	return 0;
}

//./PmergeMe 20 9 16 4 8 1 5 17