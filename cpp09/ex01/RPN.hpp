/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:21:43 by pn                #+#    #+#             */
/*   Updated: 2025/11/21 11:04:38 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

	#include <stack>
	#include <string>
	#include <iostream>
	#include <sstream>
	#include <stdexcept>
	#include <algorithm>
	#include <fstream>
	#include <limits.h>



		class RPN
		{
		private:
			std::stack<double> _stack;

		public:
			// Constructors
			RPN();
			RPN(const RPN &copy);

			// Destructor
			~RPN();

			// Operators
			RPN & operator=(const RPN &assign);

			// Getters / Setters


			// Methods
			bool isOperator(const std::string& token);
			bool isNumber(const std::string& token);
			double process(std::string& expression);
			double parseNumber(const std::string& token) const;
			void processToken(const std::string& token);
			double perform(const std::string& token, double a, double b);

};

std::ostream & operator<<(std::ostream & o, RPN const & i);

#endif