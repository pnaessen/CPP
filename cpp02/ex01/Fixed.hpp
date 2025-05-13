/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:23:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/13 16:46:27 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
