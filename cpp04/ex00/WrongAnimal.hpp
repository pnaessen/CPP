/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:40:22 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/20 07:44:36 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

	#include <string>
	#include <iostream>

	class WrongAnimal {
		protected :	
			std::string type;
		public :
			WrongAnimal();
			WrongAnimal(WrongAnimal& obj);
			virtual ~WrongAnimal();
			WrongAnimal& operator=(WrongAnimal& obj);
		
			std::string getType() const;
			void makeSound() const;
	};


#endif