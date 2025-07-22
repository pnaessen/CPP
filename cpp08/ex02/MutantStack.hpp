/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:57:23 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/22 14:49:08 by pnaessen         ###   ########lyon.fr   */
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
			typedef typename std::stack<T>::container_type::const_iterator const itc;


			MutantStack();
			MutantStack(const MutantStack& obj);
			virtual ~MutantStack();
			MutantStack& operator=(const MutantStack& obj);
			
			iterator begin();
			iterator end();
			
			const itc begin() const;
			const itc end() const;
	};

	#include "MutantStack.tpp"
	
#endif