/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:03:24 by pn                #+#    #+#             */
/*   Updated: 2025/07/09 14:51:28 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

	#include <iostream>
	#include <sstream>
	#include <stdint.h>
	#include "data.hpp"

	class Serializer {
		private:
		Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);
		~Serializer();

		public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	};
	
#endif