/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:35:34 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/07 12:12:29 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

	#define RED         "\033[31m"
	#define RESET       "\033[0m"
	
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