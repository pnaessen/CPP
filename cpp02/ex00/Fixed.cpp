/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:26:47 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/12 17:04:32 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac = 8;

Fixed::Fixed() {
	_val = 0;
	(void)_frac;
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed(const Fixed& bit) {
	std::cout << "Copy constructor called" <<std::endl;
	*this = bit;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void Fixed::setRawBits(int const raw) {
	_val = raw;
}

Fixed& Fixed::operator=(const Fixed& bit) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_val = bit.getRawBits();
	return *this;
}