/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:57:25 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/22 14:24:55 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {
	
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& obj) : std::stack<T>(obj) {
	
}

template<typename T>
MutantStack<T>::~MutantStack() {
	
}

