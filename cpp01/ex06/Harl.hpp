/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:07:42 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/09 09:37:21 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Harl {
	private:
	void error( void );
	void warning( void );
	void info( void );
	void debug( void );
	
	public:
	void complain( std::string level );
};

int stringToLevel(std::string level);
