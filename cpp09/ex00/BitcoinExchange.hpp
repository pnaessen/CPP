/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:48:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/26 13:13:33 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

	#include <algorithm>
	#include <iostream>
	#include <string>
	#include <map>
	#include <fstream>

	class Bitcoin {
		private :
			std::map<std::string, double> _map;
			//Bitcoin(char *file);
		public :

				typedef std::map<std::string, double>::iterator iterator;

			Bitcoin();
			Bitcoin(Bitcoin& obj);
			~Bitcoin();

			Bitcoin& operator=(Bitcoin& obj);
			iterator begin();
			iterator end();

			void loadDB();
		};
		
		int check_key(std::string key);
		int check_input(std::string filename);
#endif

