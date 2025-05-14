/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:23:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/14 15:41:41 by pnaessen         ###   ########lyon.fr   */
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
	static float min(float& nb, float& bit);
	 float min(const float& nb,const float& bit);
	 static float max(float& nb, float& bit);
	 float max(const float& nb,const float& bit);



	
};

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed);
