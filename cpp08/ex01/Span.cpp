/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:53:34 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/17 14:37:12 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _range(n) {
	
}

Span::Span(const Span& obj) : _range(obj._range), _vec(obj._vec) {
	
}

Span::~Span() {
	
}

void Span::addNumber(unsigned int n) {
	
	if(_vec.size() <= _range) {
		throw std::out_of_range("Span is Full");
	}
	_vec.push_back(n);
	return ;
}

unsigned int Span::shortestSpan() {
	
}