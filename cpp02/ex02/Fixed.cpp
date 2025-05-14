/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:26:47 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/14 08:52:47 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const int Fixed::_frac = 8;

Fixed::Fixed() {
	//_val = 0;
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed(const int bit) {
	std::cout << "Int constructor called" << std::endl;
	_val = bit << _frac;
}

Fixed::Fixed(const float bit) {
	std::cout << "Float constructor called" << std::endl;
	_val = roundf(bit * ( 1 << _frac));
}

Fixed::Fixed(const Fixed& bit) {
	std::cout << "Copy constructor called" <<std::endl;
	*this = bit;
}

Fixed& Fixed::operator=(const Fixed& bit) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_val = bit.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return _val;
}

void Fixed::setRawBits(int const raw) {
	_val = raw;
}

float Fixed::toFloat() const {
	
	 return (float)this->_val / (1 << _frac);
}

int Fixed::toInt() const {
	
	return this->_val >> _frac;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
