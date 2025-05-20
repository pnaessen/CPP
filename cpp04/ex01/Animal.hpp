/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:35:34 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/19 11:53:47 by pnaessen         ###   ########lyon.fr   */
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
			Animal(Animal& obj);
			virtual ~Animal();
			Animal& operator=(Animal& obj);
			
			std::string getType() const;
			virtual void makeSound() const;
	};

#endif