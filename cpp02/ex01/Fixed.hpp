/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:23:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/14 20:39:28 by pn               ###   ########lyon.fr   */
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
	~Fixed();

	 int getRawBits( void ) const;
	 void setRawBits( int const raw );
	 float toFloat(void) const;
	 int toInt(void) const;
	
};

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed);

#endif