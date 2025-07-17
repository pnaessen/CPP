/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:49:14 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/17 08:14:34 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {
	
}

template<typename T>
Array<T>::Array(const unsigned int& n) : _size(n) {
	
	if(n == 0) {
		_array = NULL;
	}
	else {
		_array = new T[n];
		for(unsigned int i = 0; i < n; i++) {
			_array[i] = T();
		}
	}
}

template<typename T>
Array<T>::Array(const Array& obj) : _size(obj._size) {
	
	if(obj._size == 0) {
		_array = NULL;
	}
	else {
		_array = new T[_size];
		for(unsigned int i = 0; i < _size; i++) {
			_array[i] = obj._array[i];
		}
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& obj) {
	
	if(this != &obj) {
		delete[] _array;
		
		_size = obj._size;
		if(_size == 0) {
			_array = NULL;
		}
		else {
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = obj._array[i];
			}
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array() {
	
	delete[] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
	
	if(index >= _size) {
		throw std::out_of_range("Index out of range");
	}
	return _array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size) {
		throw std::out_of_range("Index out of range");
	}
	return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}
