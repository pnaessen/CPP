/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:59:05 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/16 10:02:23 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP 

	#include <string>
	#include <iostream>

	template <typename T >
	
	void iter(T *array, int length, void(*f)(T &)) {
		if(!array || length <= 0 || !f)
			return ;
		for(int i = 0; i < length; i++) {
			f(array[i]);
		}
	}
	
	template <typename T >
	void iter(T *array, int length, void(*f)(const T &)) {
		if(!array || length <= 0 || !f )
			return ;
		for(int i = 0; i < length; i++) {
			f(array[i]);
		}
	}
	
#endif