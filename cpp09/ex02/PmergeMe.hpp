/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:48 by pnaessen          #+#    #+#             */
/*   Updated: 2025/10/30 16:22:38 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
#include <climits>

    #define KRESET "\033[0m"
    #define KBOLD  "\033[1m"
    #define KBLUE  "\033[34m"
    #define KCYAN  "\033[36m"
    #define KMAG   "\033[35m"
    #define KGRN   "\033[32m"
    #define KYEL   "\033[33m"


template <typename Container>
class PmergeMe
{
	private:
		Container _data;
		size_t _size;

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const& copy);
		~PmergeMe(void);

		PmergeMe &	operator=(PmergeMe const& assign);
		void processParsing(int argc, char **argv);
		size_t getData(size_t idx);
		size_t getSize();
		void createInitialPairs(std::vector<std::vector<int> >& groups);

};

template <typename Container>
std::ostream& operator<<(std::ostream& os, PmergeMe<Container>& merge);
void printVdeV(const std::vector<std::vector<int> >& groups);
#include "PmergeMe.tpp"

#endif /* PMERGEME_HPP */