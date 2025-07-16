/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:10:41 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/16 12:47:36 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

	#include <string>
	#include <iostream>

	template<typename T>
	class Array {
		private :
			T *_array;
			unsigned int _size;
			
		public :
		Array();
		Array(const unsigned int& n);
		Array(const Array& obj);
		~Array();
		
		Array& operator=(const Array& obj);
		T& operator[](unsigned int &n);
		unsigned int size() const;
	};
	
#endif