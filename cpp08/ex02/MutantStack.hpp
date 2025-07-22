/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:57:23 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/22 12:52:22 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


	#include <iostream>
	#include <algorithm>
	#include <string>
	#include <exception>
	#include <stack>
	
	template<typename T>
	class MutantStack : public std::stack<T> {
		
		private:

		public:

			typedef typename std::stack<T>::container_type::iterator iterator;

			MutantStack();
			MutantStack(const MutantStack& obj);
			~MutantStack();
			MutantStack& operator=(const MutantStack& obj);
			void push(int n);
			iterator begin();
			iterator end();
	};

	#include "MutantStack.tpp"
	
#endif