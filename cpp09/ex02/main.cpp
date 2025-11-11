/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:43 by pnaessen          #+#    #+#             */
/*   Updated: 2025/11/11 17:56:12 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if(argc < 2) {
		std::cerr << "Usage: " << argv[0] << " 20 9 16 4 8 1 5 17 [...] 32 24 11 13" << std::endl;
		return 1;
	}

    struct timeval start, end;
    gettimeofday(&start, NULL);
	std::vector<std::vector<int> > groups;
	//PmergeMe<std::vector<int> > merge;
	PmergeMe<std::deque<int> > test;

	try
	{
		test.processParsing(argc, argv);
		std::cout << "Before: " << test << std::endl;
		test.createInitialPairs(groups);

		if(test.checkSorted()) {
			std::cout << "After merge insert sort\n" << std::endl;
			std::cout << test << std::endl;
		}
		gettimeofday(&end, NULL);
        double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
        std::cout << "Operation took " << duration << " seconds." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}

//./PmergeMe 20 9 16 4 8 1 5 17