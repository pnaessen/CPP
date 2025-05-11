/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:26:47 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/11 14:44:51 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	_val = 0;
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed(const Fixed& bit) {
	_val = bit;
	std::cout << "Copy constructor called" <<std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return 0;
}

void Fixed::setRawBits(int const raw) {
	
}