/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:53:19 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/21 14:52:40 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(60);
	
	std::vector<int> vec { 1, 2, 3, 4, 5 };
	 sp.addNumber(-18);
	 sp.addNumber(3);
	 sp.addNumber(17);
	 sp.addNumber(9);
	 sp.addNumber(10);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.addMoreNumber(vec);
	return 0;
}