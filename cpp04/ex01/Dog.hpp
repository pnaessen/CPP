/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:28:12 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/19 17:12:13 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private :
	Brain* ideas;
	
	public :
	Dog();
	Dog(Dog& obj);
	~Dog();
	Dog& operator=(Dog& obj);
	
	void makeSound() const;
};

#endif