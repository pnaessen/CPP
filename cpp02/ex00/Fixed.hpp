/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:23:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/11 14:36:45 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Fixed {
	private :
	int _val;
	static const int _frac;
	
	public:
	Fixed();
	Fixed(const Fixed& bit);
	Fixed& operator=(const Fixed& bit);
	~Fixed();

	 int getRawBits( void ) const;
	 void setRawBits( int const raw );
	
};