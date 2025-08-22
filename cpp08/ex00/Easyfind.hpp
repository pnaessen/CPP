/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:37:16 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/22 13:29:22 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

	#include <iostream>
	#include <string>
	#include <exception>
	#include <vector>
	#include <list>
	#include <stack>
	#include <algorithm>
	
	
	template<typename T>
	typename T::iterator easyfind(T& container, int value) {
		
		typename T::iterator it = std::find(container.begin(), container.end(), value);
		if (it == container.end()) {
			throw std::runtime_error("Value not found");
		}
		return it;
	}
	
#endif