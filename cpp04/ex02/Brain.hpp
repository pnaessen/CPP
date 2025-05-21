/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:45:28 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/21 15:48:08 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	protected :
		std::string ideas[100];

	public :
		Brain();
		Brain(const Brain& obj);
		~Brain();
		Brain& operator=(const Brain& obj);

		std::string getIdeas(int index);
		void setIdeas(int idx, std::string idea);
};

#endif