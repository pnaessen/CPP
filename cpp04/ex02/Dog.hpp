/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:28:12 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/21 15:44:30 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private :
	Brain *ideas;

	public :
	Dog();
	Dog(const Dog& obj);
	~Dog();
	Dog& operator=(const Dog& obj);
	
	void makeSound() const;
	Brain* getBrain();
};

#endif