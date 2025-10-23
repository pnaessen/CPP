/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:48 by pnaessen          #+#    #+#             */
/*   Updated: 2025/10/23 18:13:25 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
#include <climits>

//TODO make tempate class for dequeu and vector 
class PmergeMe
{
	private:
		std::vector<int> _data;
		size_t _size;

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const& copy);
		~PmergeMe(void);

		PmergeMe &	operator=(PmergeMe const& assign);
		void processParsing(int argc, char **argv);
		size_t getData(size_t idx);
		size_t getSize();
		void mergeInsert();

};

std::ostream&	operator<<(std::ostream& os, PmergeMe& merge);

#endif /* PMERGEME_HPP */