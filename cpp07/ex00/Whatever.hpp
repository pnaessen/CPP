/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:34:01 by pn                #+#    #+#             */
/*   Updated: 2025/07/15 13:57:34 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

	#include <string>
	#include <iostream>

	template <typename T>
	void swap(T &s1,T &s2) {
		T tmp = s1;
		s1 = s2;
		s2 = tmp;
	};
	
	template <typename T>
	T max (T &x, T &y) {
		return ( x >= y ? x : y);
	};

	template <typename T>
	T  min (T &x, T &y) {
		return ( x >= y ? y : x);
	}


#endif