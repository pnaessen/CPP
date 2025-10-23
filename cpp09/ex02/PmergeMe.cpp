/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:46 by pnaessen          #+#    #+#             */
/*   Updated: 2025/10/23 12:14:43 by pnaessen         ###   ########lyon.fr   */
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

int PmergeMe::getData(int idx) {
	return _data[idx];
}

std::ostream& operator<<(std::ostream& os, PmergeMe& i) {

	os << i.getData(0);
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
}