/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:07:42 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/08 13:21:53 by pnaessen         ###   ########lyon.fr   */
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