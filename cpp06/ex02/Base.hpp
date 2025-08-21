/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:57:33 by pn                #+#    #+#             */
/*   Updated: 2025/08/21 10:17:11 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

	#include <iostream>
	#include <cstdlib>
	#include <ctime>


	class Base {
		private:
		
		public:
		Base();
		virtual ~Base();
	};
	
	Base* generate(void);
	void identify(Base* p);
	void identify(Base& p);
	
#endif