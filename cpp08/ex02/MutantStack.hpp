/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:57:23 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/22 14:24:12 by pnaessen         ###   ########lyon.fr   */
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
			//std::stack<T> _mStack;
		public:

			typedef typename std::stack<T>::container_type::iterator iterator;

			MutantStack();
			MutantStack(const MutantStack& obj);
			virtual ~MutantStack();
			MutantStack& operator=(const MutantStack& obj);
			
			iterator begin();
			iterator end();
	};

	#include "MutantStack.tpp"
	
#endif