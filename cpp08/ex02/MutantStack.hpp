/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:57:23 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/22 09:08:35 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


	#include <iostream>
	#include <algorithm>
	#include <string>
	#include <exception>

	template<typename T>
	class MutantStack {
		
		private:

		public:
			MutantStack();
			MutantStack(const MutantStack& obj);
			~MutantStack();
			MutantStack& operator=(const MutantStack& obj);
			void push(int n);
			T& top();
			void pop();
			T& size()
			T& begin();
			T& end();
	};


#endif