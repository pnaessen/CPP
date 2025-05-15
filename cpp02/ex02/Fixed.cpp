/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:26:47 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/15 09:57:59 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const int Fixed::_frac = 8;

Fixed::Fixed() {
	//std::cout << "Default constructor called" <<std::endl;
	_val = 0;
}

Fixed::Fixed(const int bit) {
	//std::cout << "Int constructor called" << std::endl;
	_val = bit << _frac;
}

Fixed::Fixed(const float bit) {
	//std::cout << "Float constructor called" << std::endl;
	_val = roundf(bit * ( 1 << _frac));
}

Fixed::Fixed(const Fixed& bit) {
	//std::cout << "Copy constructor called" <<std::endl;
	*this = bit;
}

Fixed& Fixed::operator=(const Fixed& bit) {
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_val = bit.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator>(const Fixed& bit) const {
	return _val > bit.getRawBits();
}

bool Fixed::operator<(const Fixed& bit) const {
	return _val < bit.getRawBits();
}

bool Fixed::operator>=(const Fixed& bit) const {
	return _val >= bit.getRawBits();
}

bool Fixed::operator<=(const Fixed& bit) const {
	return _val <= bit.getRawBits();
}
bool Fixed::operator==(const Fixed& bit) const {
	return _val == bit.getRawBits();
}

bool Fixed::operator!=(const Fixed& bit) const {
	return _val != bit.getRawBits();
}

Fixed Fixed::operator+(const Fixed& bit) const {
	Fixed add;
	add.setRawBits(_val + bit.getRawBits());
	return add;
}

Fixed Fixed::operator-(const Fixed& bit) const {
	Fixed sub;
	sub.setRawBits(_val - bit.getRawBits());
	return sub;
}

Fixed Fixed::operator*(const Fixed& bit) const {
	Fixed mul;
	mul.setRawBits(_val * bit.getRawBits() >> _frac);
	return mul;
}

Fixed Fixed::operator/(const Fixed& bit) const {
	Fixed div;
	div.setRawBits(_val / bit.getRawBits() << _frac);
	return div;
}

Fixed& Fixed::min(Fixed& obj, Fixed& obj2) {
	if (obj.getRawBits() > obj2.getRawBits())
		return obj2;
	return obj;
}

const Fixed& Fixed::min(const Fixed& obj, const Fixed& obj2) {
	if (obj.getRawBits() > obj2.getRawBits())
		return obj2;
	return obj;
}

Fixed& Fixed::max(Fixed& obj, Fixed& obj2) {
	if (obj.getRawBits() > obj2.getRawBits())
		return obj;
	return obj2;
}

const Fixed& Fixed::max(const Fixed& obj, const Fixed& obj2) {
	if (obj.getRawBits() > obj2.getRawBits())
		return obj;
	return obj2;
}

Fixed Fixed::operator++() {
	_val++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this; 
	_val++;
	return tmp;
}

Fixed Fixed::operator--() {
	_val--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this; 
	_val--;
	return tmp;
}