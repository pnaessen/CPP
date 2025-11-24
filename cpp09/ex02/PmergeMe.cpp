/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:46 by pnaessen          #+#    #+#             */
/*   Updated: 2025/11/03 20:06:39 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(PmergeMe const& copy) : _vector(copy._vector), _deque(copy._deque) {

}

PmergeMe::~PmergeMe() {

}

PmergeMe & PmergeMe::operator=(PmergeMe const& assign) {
	if (this != &assign) {
		_vector = assign._vector;
		_deque = assign._deque;
	}
	return *this;
}


static bool parsePositiveInt(const char *token, int& outValue) {
	if (!token || *token == '\0')
		return false;
	if (std::strchr(token, '.'))
		return false;

	char *end = NULL;
	long val = std::strtol(token, &end, 10);

	if (end == token || *end != '\0')
		return false;
	if (val < 0 || val > INT_MAX)
		return false;

	outValue = static_cast<int>(val);
	return true;
}


void PmergeMe::run(int argc, char **argv) {
	_vector.clear();
	_deque.clear();

	for (int i = 1; i < argc; i++) {
		int value = 0;
		if (!parsePositiveInt(argv[i], value)) {
			std::cerr << "Error: Invalid token '" << argv[i] << "'" << std::endl;
			return;
		}
		_vector.push_back(value);
		_deque.push_back(value);
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i] << (i < _vector.size() - 1 ? " " : "");
	}
	std::cout << std::endl;

	struct timeval startVec, endVec;
	gettimeofday(&startVec, NULL);

	std::vector<std::vector<int> > vecGroups;
	_createPairsVector(vecGroups);


	gettimeofday(&endVec, NULL);
	double timeVec = (endVec.tv_sec - startVec.tv_sec) + (endVec.tv_usec - startVec.tv_usec) / 1000000.0;

	struct timeval startDeq, endDeq;
	gettimeofday(&startDeq, NULL);

	std::deque<std::deque<int> > deqGroups;
	_createPairsDeque(deqGroups);

	gettimeofday(&endDeq, NULL);
	double timeDeq = (endDeq.tv_sec - startDeq.tv_sec) + (endDeq.tv_usec - startDeq.tv_usec) / 1000000.0;

	std::cout << "------------------------" << std::endl;
	std::cout << "After:  ";
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i] << (i < _vector.size() - 1 ? " " : "");
	}
	std::cout << std::endl << std::endl;

	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " s" << std::endl;

	std::cout << "Time to process a range of " << _deque.size()
			  << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " s" << std::endl;
}


void PmergeMe::_createPairsVector(std::vector<std::vector<int> >& groups) {
	std::vector<int> tomThumb;
	bool hasOddElement = (_vector.size() % 2 != 0);

	if (hasOddElement) {
		std::vector<int> singleElement;
		singleElement.push_back(_vector.back());
		tomThumb = singleElement;
		_vector.pop_back();
	}

	for (size_t i = 0; i < _vector.size(); i += 2) {
		std::vector<int> pair;
		if (_vector[i] > _vector[i + 1]) {
			pair.push_back(_vector[i + 1]);
			pair.push_back(_vector[i]);
		}
		else {
			pair.push_back(_vector[i]);
			pair.push_back(_vector[i + 1]);
		}
		groups.push_back(pair);
	}

	_sortVector(groups);

	if (!tomThumb.empty()) {
		std::vector<std::vector<int> >::iterator it =
			std::lower_bound(groups.begin(), groups.end(), tomThumb);
		groups.insert(it, tomThumb);
	}

	_vector.clear();
	for(size_t i = 0; i < groups.size(); i++) {
		_vector.insert(_vector.end(), groups[i].begin(), groups[i].end());
	}
}

void PmergeMe::_sortVector(std::vector<std::vector<int> >& groups) {
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

	_sortVector(newGroups);

	groups = newGroups;
	_unPairVector(groups);

	if (!leftover.empty()) {
		if (leftover.size() > 1) {
			std::vector<std::vector<int> > leftoverGroups;
			leftoverGroups.push_back(leftover);
			_unPairVector(leftoverGroups);

			for (size_t i = 0; i < leftoverGroups.size(); ++i) {
				std::vector<std::vector<int> >::iterator it =
					std::lower_bound(groups.begin(), groups.end(), leftoverGroups[i]);
				groups.insert(it, leftoverGroups[i]);
			}
		}
		else {
			std::vector<std::vector<int> >::iterator it =
				std::lower_bound(groups.begin(), groups.end(), leftover);
			groups.insert(it, leftover);
		}
	}
}

void PmergeMe::_unPairVector(std::vector<std::vector<int> >& groups) {
	if (groups.empty())
		return;

	bool allSizeOne = true;
	for (size_t i = 0; i < groups.size(); ++i) {
		if (groups[i].size() > 1) {
			allSizeOne = false;
			break;
		}
	}
	if (allSizeOne)
		return;

	std::vector<std::vector<int> > result;
	for (size_t i = 0; i < groups.size(); ++i) {
		const std::vector<int>& g = groups[i];
		if (g.size() <= 1) {
			result.push_back(g);
			continue;
		}
		size_t half = g.size() / 2;
		std::vector<int> first(g.begin(), g.begin() + half);
		std::vector<int> second(g.begin() + half, g.end());
		result.push_back(first);
		result.push_back(second);
	}
	groups.swap(result);

	std::vector<std::vector<int> > pend;
	std::vector<std::vector<int> > main;
	for (size_t i = 0; i < groups.size(); i++) {
		if (i % 2 == 0) {
		main.push_back(groups[i]);
		}
		else {
			pend.push_back(groups[i]);
		}
	}

	std::vector<size_t> jacobIndices;
	if (!pend.empty())
		jacobIndices.push_back(0);

	size_t prevJacob = 1;
	size_t currJacob = 3;
	while (jacobIndices.size() < pend.size()) {

		size_t right = currJacob;

		if (right > pend.size()) {
			right = pend.size();
		}
		for (size_t i = right; i > prevJacob; --i) {
			jacobIndices.push_back(i - 1);
		}

		size_t nextJacob = currJacob + 2 * prevJacob;
		prevJacob = currJacob;
		currJacob = nextJacob;
	}

	for (size_t i = 0; i < jacobIndices.size(); i++) {

		size_t idx = jacobIndices[i];
		if (idx < pend.size()) {
			std::vector<int> itemToInsert = pend[idx];
			std::vector<std::vector<int> >::iterator it =
				std::lower_bound(main.begin(), main.end(), itemToInsert);
			main.insert(it, itemToInsert);
		}
	}

	groups = main;
	_unPairVector(groups);
}

void PmergeMe::_createPairsDeque(std::deque<std::deque<int> >& groups) {
	std::deque<int> tomThumb;
	bool hasOddElement = (_deque.size() % 2 != 0);

	if (hasOddElement) {
		std::deque<int> singleElement;
		singleElement.push_back(_deque.back());
		tomThumb = singleElement;
		_deque.pop_back();
	}

	for (size_t i = 0; i < _deque.size(); i += 2) {
		std::deque<int> pair;
		if (_deque[i] > _deque[i + 1]) {
			pair.push_back(_deque[i + 1]);
			pair.push_back(_deque[i]);
		}
		else {
			pair.push_back(_deque[i]);
			pair.push_back(_deque[i + 1]);
		}
		groups.push_back(pair);
	}

	_sortDeque(groups);

	if (!tomThumb.empty()) {
		std::deque<std::deque<int> >::iterator it =
			std::lower_bound(groups.begin(), groups.end(), tomThumb);
		groups.insert(it, tomThumb);
	}

	_deque.clear();
	for(size_t i = 0; i < groups.size(); i++) {
		_deque.insert(_deque.end(), groups[i].begin(), groups[i].end());
	}
}

void PmergeMe::_sortDeque(std::deque<std::deque<int> >& groups) {

	if (groups.size() <= 1)
		return;

	std::deque<int> leftover;
	if (groups.size() % 2 != 0) {
		leftover = groups.back();
		groups.pop_back();
	}

	std::deque<std::deque<int> > newGroups;
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

	_sortDeque(newGroups);

	groups = newGroups;
	_unPairDeque(groups);

	if (!leftover.empty()) {
		if (leftover.size() > 1) {
			std::deque<std::deque<int> > leftoverGroups;
			leftoverGroups.push_back(leftover);
			_unPairDeque(leftoverGroups);

			for (size_t i = 0; i < leftoverGroups.size(); ++i) {
				std::deque<std::deque<int> >::iterator it =
					std::lower_bound(groups.begin(), groups.end(), leftoverGroups[i]);
				groups.insert(it, leftoverGroups[i]);
			}
		}
		else {
			std::deque<std::deque<int> >::iterator it =
				std::lower_bound(groups.begin(), groups.end(), leftover);
			groups.insert(it, leftover);
		}
	}
}

void PmergeMe::_unPairDeque(std::deque<std::deque<int> >& groups) {

	if (groups.empty()) {
		return;
	}

	bool allSizeOne = true;
	for (size_t i = 0; i < groups.size(); ++i) {
		if (groups[i].size() > 1) {
			allSizeOne = false;
			break;
		}
	}
	if (allSizeOne) return;

	std::deque<std::deque<int> > result;
	for (size_t i = 0; i < groups.size(); ++i) {
		const std::deque<int>& g = groups[i];

		if (g.size() <= 1) {
			result.push_back(g);
			continue;
		}
		size_t half = g.size() / 2;
		std::deque<int> first(g.begin(), g.begin() + half);
		std::deque<int> second(g.begin() + half, g.end());
		result.push_back(first);
		result.push_back(second);
	}
	groups.swap(result);

	std::deque<std::deque<int> > pend;
	std::deque<std::deque<int> > main;
	for (size_t i = 0; i < groups.size(); i++) {

		if (i % 2 == 0) {
			main.push_back(groups[i]);
		}
		else {

		    pend.push_back(groups[i]);
		}
	}

	std::vector<size_t> jacobIndices;
	if (!pend.empty())
		jacobIndices.push_back(0);

	size_t prevJacob = 1;
	size_t currJacob = 3;
	while (jacobIndices.size() < pend.size()) {

		size_t right = currJacob;
		if (right > pend.size()) {
		 right = pend.size();
		}
		for (size_t i = right; i > prevJacob; --i) {
			jacobIndices.push_back(i - 1);
		}
		size_t nextJacob = currJacob + 2 * prevJacob;
		prevJacob = currJacob;
		currJacob = nextJacob;
	}

	for (size_t i = 0; i < jacobIndices.size(); i++) {
		size_t idx = jacobIndices[i];
		if (idx < pend.size()) {
			std::deque<int> itemToInsert = pend[idx];
			std::deque<std::deque<int> >::iterator it =
				std::lower_bound(main.begin(), main.end(), itemToInsert);
			main.insert(it, itemToInsert);
		}
	}

	groups = main;
	_unPairDeque(groups);
}