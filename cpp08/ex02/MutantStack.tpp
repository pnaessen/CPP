/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:57:25 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/26 08:49:23 by pnaessen         ###   ########lyon.fr   */
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

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& obj) {
	
	if(this != &obj) {
		std::stack<T>::operator=(obj);
	}

	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::itc MutantStack<T>::begin() const {
	
	return this->c.begin();
}

template<typename T>
 typename MutantStack<T>::itc MutantStack<T>::end() const {
	
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::riterator MutantStack<T>::rbegin() {
	
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::riterator MutantStack<T>::rend() {

	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::ritc MutantStack<T>::rbegin() const {
	
	return this->c.rbegin();
}

template<typename T>
 typename MutantStack<T>::ritc MutantStack<T>::rend() const {
	
	return this->c.rend();
}
