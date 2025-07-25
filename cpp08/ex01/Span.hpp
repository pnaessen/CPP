/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:53:47 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/22 08:49:52 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

	#include <iostream>
	#include <string>
	#include <exception>
	#include <vector>
	#include <algorithm>

	class Span {
		private:
			unsigned int _range;
			std::vector<int> _vec;
			Span();

		public:
			Span(unsigned int n);
			Span(const Span& obj);
			~Span();
			Span& operator=(const Span& obj);
			void addNumber(unsigned int n);
			unsigned int shortestSpan();
			unsigned int longestSpan();
			void addMoreNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	};

#endif