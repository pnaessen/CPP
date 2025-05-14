/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:23:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/14 20:38:54 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
	private :
	int _val;
	static const int _frac;
	
	public:
	Fixed();
	Fixed(const Fixed& );
	Fixed& operator=(const Fixed& bit);
	~Fixed();

	 int getRawBits( void ) const;
	 void setRawBits( int const raw );
	
};

#endif