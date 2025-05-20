/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:36 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/20 11:56:31 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private :
	Brain *ideas;
	
	public :
	Cat();
	Cat(Cat& obj);
	~Cat();
	Cat& operator=(Cat& obj);
	
	void  makeSound() const;
	Brain* getBrain();

};

#endif