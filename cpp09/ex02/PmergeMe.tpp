/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:46 by pnaessen          #+#    #+#             */
/*   Updated: 2025/10/30 10:55:08 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe() : _data(), _size(0) {}

template <typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe const& copy) : _data(copy._data), _size(copy._size) {}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(PmergeMe const& assign) {
	if (this != &assign) {
		_data = assign._data;
		_size = assign._size;
	}
	return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
size_t PmergeMe<Container>::getSize() {
	return _data.size();
}

template <typename Container>
size_t PmergeMe<Container>::getData(size_t idx) {
	if (_data.size() <= idx)
		throw std::out_of_range("Index out of range");
	return _data[idx];
}

template <typename Container>
std::ostream& operator<<(std::ostream& os, PmergeMe<Container>& merge) {
	for (size_t i = 0; i < merge.getSize(); i++) {
		os << merge.getData(i) << " ";
	}
	return os;
}

static bool parsePositiveInt(const char *token, int& outValue) {
	if (!token || *token == '\0') {
		return false;
	}
	char *end = NULL;
	unsigned int val = strtod(token, &end);
	if (end == token || *end != '\0') {
		return false;
	}
	if (val > INT_MAX || val == 0) {
		return false;
	}
	outValue = val;
	return true;
}

template <typename Container>
void PmergeMe<Container>::processParsing(int argc, char** argv) {
	_data.clear();
	for (int i = 1; i < argc; i++) {
		int value = 0;
		if (!parsePositiveInt(argv[i], value)) {
			throw std::invalid_argument("Invalid token: only positive integers are allowed");
		}
		_data.push_back(value);
	}
	_size = _data.size();
}

void mergeInsertSort(std::vector<std::vector<int> >& groups) {

	std::cout << "==============================S" << std::endl;
	std::cout << "Print groups\n" << std::endl;
	printVdeV(groups);
	std::cout << "==============================E" << std::endl;
	if (groups.size() <= 1)
        return;

    std::vector<int> leftover;
    if (groups.size() % 2 != 0) {
        leftover = groups.back();
        groups.pop_back();
    }

    std::vector<std::vector<int> > newGroups;
    for (size_t i = 0; i < groups.size(); i += 2) {
        if (groups[i].back() < groups[i + 1].back()) {
            groups[i].insert(groups[i].end(), groups[i + 1].begin(), groups[i + 1].end());
            newGroups.push_back(groups[i]);
        }
		else {
            groups[i + 1].insert(groups[i + 1].end(), groups[i].begin(), groups[i].end());
            newGroups.push_back(groups[i + 1]);
        }
    }


	std::cout << "==============================S" << std::endl;
	std::cout << "print newgroups\n" << std::endl;
	printVdeV(newGroups);
	std::cout << "==============================E" << std::endl;
    mergeInsertSort(newGroups);

    //then insert

    groups = newGroups;
	std::cout << "print groups end recu" << std::endl;
	printVdeV(groups);
}


template<typename Container>
void PmergeMe<Container>::createInitialPairs(std::vector<std::vector<int> >& groups) {

    bool hasOddElement = (_data.size() % 2 != 0);
    int tomThumb = -1;

    if (hasOddElement) {
        tomThumb = _data.back();
        _data.pop_back();
    }

    for (size_t i = 0; i < _data.size(); i += 2) {
        std::vector<int> pair;
        if (_data[i] > _data[i + 1]) {
            pair.push_back(_data[i + 1]);
            pair.push_back(_data[i]);
        } else {
            pair.push_back(_data[i]);
            pair.push_back(_data[i + 1]);
        }
        groups.push_back(pair);
    }
	// do something with the last
}

void printVdeV(std::vector<std::vector<int> >& groups) {

	for(size_t i = 0; i <= groups.size() - 1; i++) {

		std::cout << "groups [" << i << "]: ";
		for(size_t j = 0; j < groups[i].size(); j++) {
			std::cout << groups[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
