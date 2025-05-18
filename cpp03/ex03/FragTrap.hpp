/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:18:28 by pn                #+#    #+#             */
/*   Updated: 2025/05/18 22:43:10 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& obj);
		~FragTrap();
		
		FragTrap& operator=(const FragTrap& obj);

		void attack(const std::string& target);
		void highFivesGuys();
};

#endif