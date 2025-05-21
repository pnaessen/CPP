/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:36 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/21 15:43:01 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	private :

	public :
	Cat();
	Cat(const Cat& obj);
	~Cat();
	Cat& operator=(const Cat& obj);
	
	void  makeSound() const;
};

#endif