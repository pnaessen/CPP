/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:48 by pnaessen          #+#    #+#             */
/*   Updated: 2025/11/24 09:16:50 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
#include <climits>
#include <ctime>
#include <sys/time.h>
#include <deque>
#include <cstring>
#include <iomanip>


    #define KRESET "\033[0m"
    #define KBOLD  "\033[1m"
    #define KBLUE  "\033[34m"
    #define KCYAN  "\033[36m"
    #define KMAG   "\033[35m"
	#define KRED   "\033[37m"
    #define KGRN   "\033[32m"
    #define KYEL   "\033[33m"


class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int>  _deque;

		//  Gestion VECTOR
		void _sortVector(std::vector<std::vector<int> >& groups);
		void _unPairVector(std::vector<std::vector<int> >& groups);
		void _createPairsVector(std::vector<std::vector<int> >& groups);

		//  Gestion DEQUE
		void _sortDeque(std::deque<std::deque<int> >& groups);
		void _unPairDeque(std::deque<std::deque<int> >& groups);
		void _createPairsDeque(std::deque<std::deque<int> >& groups);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const& copy);
		~PmergeMe();

		PmergeMe & operator=(PmergeMe const& assign);

		void run(int argc, char **argv);
};


#endif /* PMERGEME_HPP */