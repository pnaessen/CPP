/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:23:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/15 08:47:02 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
	private :
	int _val;
	static const int _frac;
	
	public:
	Fixed();
	Fixed(const int bit);
	Fixed(const float bit);
	Fixed(const Fixed& );
	~Fixed();
	
	Fixed& operator=(const Fixed& bit);
	bool operator>(const Fixed& bit) const;
	bool operator<(const Fixed& bit) const;
	bool operator>=(const Fixed& bit) const;
	bool operator<=(const Fixed& bit) const;
	bool operator==(const Fixed& bit) const;
	bool operator!=(const Fixed& bit) const;
	
	Fixed operator+(const Fixed& bit) const;
	Fixed operator-(const Fixed& bit) const;
	Fixed operator*(const Fixed& bit) const;
	Fixed operator/(const Fixed& bit) const;

	Fixed operator++();
	Fixed operator++(int bit);
	Fixed operator--();
	Fixed operator--(int bit);

	 int getRawBits( void ) const;
	 void setRawBits( int const raw );
	 float toFloat(void) const;
	 int toInt(void) const;
	static Fixed& min(Fixed& obj, Fixed& obj2);
	static const Fixed& min(const Fixed& obj,const Fixed& obj2);
	static Fixed& max(Fixed& obj, Fixed& obj2);
	static const Fixed& max(const Fixed& obj,const Fixed& obj2);

	
};

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed);

#endif