/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:46 by pnaessen          #+#    #+#             */
/*   Updated: 2025/10/23 18:02:36 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(PmergeMe const& copy): _data(copy._data) {

}

PmergeMe& PmergeMe::operator=(PmergeMe const& assign) {

	if(this != &assign) {
		_data = assign._data;
	}
	return *this;
}


PmergeMe::~PmergeMe() {

}

size_t PmergeMe::getSize() {
	return _data.size();
}

size_t PmergeMe::getData(size_t idx) {

	if(_data.size() <= idx)
		throw std::out_of_range("Index out of range");
	return _data[idx];
}

std::ostream& operator<<(std::ostream& os, PmergeMe& merge) {

	for (size_t i = 0; i < merge.getSize() ; i++)
	{
		os << merge.getData(i) << " ";
	}

	return os;
}


bool parsePositiveInt(const char *token, int& outValue) {

	if(!token || *token == '\0') {
		return false;
	}

	char *end = NULL;
	unsigned int val = strtod(token, &end);
	if(end == token || *end != '\0') {
		return false;
	}
	if(val > INT_MAX || val == 0) {
		return false;
	}
	outValue = val;
	return true;
}

void PmergeMe::processParsing(int argc, char** argv) {

	_data.clear();
	for (int i = 1; i < argc; i++) {
		int value = 0;
		if(!parsePositiveInt(argv[i], value)) {
			throw std::invalid_argument("Invalid token: only positive integers are allowed");
		}
		_data.push_back(value);
	}
	_size = _data.size();
}

void PmergeMe::mergeInsert() {

	if(_size <= 1) {
		return ;
	}


}