/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:23:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/14 21:24:20 by pn               ###   ########lyon.fr   */
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


	~Fixed();

	 int getRawBits( void ) const;
	 void setRawBits( int const raw );
	 float toFloat(void) const;
	 int toInt(void) const;
	static Fixed& min(Fixed& nb, Fixed& bit);
	static const Fixed& min(const Fixed& nb,const Fixed& bit);
	static Fixed& max(Fixed& nb, Fixed& bit);
	static const Fixed& max(const Fixed& nb,const Fixed& bit);

	
};

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed);

#endif