/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:48:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/24 16:00:46 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

	#include <algorithm>
	#include <iostream>
	#include <string>
	#include <map>

	class Bitcoin {
		private :
			std::map<std::string, double> _map;
			Bitcoin();
		public :
			Bitcoin(char *file);
			Bitcoin(Bitcoin& obj);
			~Bitcoin();

			Bitcoin& operator=(Bitcoin& obj);
	};

#endif

