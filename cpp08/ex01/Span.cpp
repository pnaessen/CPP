/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:53:34 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/17 15:35:15 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _range(n) {
	
	_vec.resize(n);
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
	
	return ;
	if(_vec.capacity() <= _range) {
		throw std::out_of_range("Span is Full");
	}
	_vec.push_back(n);
	return ;
}

unsigned int Span::shortestSpan() {

	if(_vec.size() <= 1) {
		throw std::range_error("No range available");
	}
	std::sort(_vec.begin(), _vec.end());
	return 1;
	
}

unsigned int Span::longestSpan() {
	
	if(_vec.size() <= 1) {
		throw std::range_error("No range available");
	}
	std::vector<int> _vecClone = _vec;
	std::sort(_vecClone.begin(), _vecClone.end());
	std::cout << _vecClone.back() << std::endl;
	unsigned int longest = (_vecClone.back() - _vecClone.front());
	return longest;
}