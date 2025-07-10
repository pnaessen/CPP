/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:57:33 by pn                #+#    #+#             */
/*   Updated: 2025/07/10 10:07:15 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

	#include <iostream>
	#include <cstdlib>
	#include <ctime>
	#include <typeinfo>


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