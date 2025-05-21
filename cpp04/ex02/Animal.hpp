/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:35:34 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/21 20:20:42 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

	#include <string>
	#include <iostream>
	
	class Animal {
		protected :	
			std::string type;
		public :
			Animal();
			Animal(const Animal& obj);
			virtual ~Animal();
			Animal& operator=(const Animal& obj);
			
			std::string getType() const;
			virtual void makeSound() const = 0;
	};

#endif