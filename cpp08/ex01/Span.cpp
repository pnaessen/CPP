/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:53:34 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/21 09:11:33 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _range(n) {
	
}

Span::Span(const Span& obj) : _range(obj._range), _vec(obj._vec) {
	
}

Span::~Span() {
	
}

Span& Span::operator=(Span& obj) {
	
	if( this != &obj) {
		_range = obj._range;
		_vec = obj._vec;
	}
	return *this;
}

void Span::addNumber(unsigned int n) {
	
	if(_vec.size() >= _range) {
		throw std::out_of_range("Span is Full");
	}
	_vec.push_back(n);
}

unsigned int Span::shortestSpan() {

	if(_vec.size() <= 1) {
		throw std::range_error("No range available");
	}
	std::vector<int> _vecClone = _vec;
	std::sort(_vecClone.begin(), _vecClone.end());
	return 1;
	
}

unsigned int Span::longestSpan() {
	
	if(_vec.size() <= 1) {
		throw std::range_error("No range available");
	}
	std::vector<int> _vecClone = _vec;
	std::sort(_vecClone.begin(), _vecClone.end());
	int longest = _vecClone.back() - _vecClone.front();
	
	return longest;
}