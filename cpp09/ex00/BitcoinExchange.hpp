/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:48:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/02 15:52:37 by pn               ###   ########lyon.fr   */
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
		private:
  			  std::map<std::string, double> _exchangeRates;
			  void processLine(const std::string& line) const;
    
		public:
    		  typedef std::map<std::string, double>::const_iterator const_iterator;
    
   		 Bitcoin();
  		 Bitcoin(const Bitcoin& obj);
  		 ~Bitcoin();
   		 Bitcoin& operator=(const Bitcoin& obj);
    
    	 const_iterator begin() const ;
   		 const_iterator end() const ;
    
    bool loadDB(const std::string& filename);
    double getExchangeRate(const std::string& date) const;
    bool processInput(const std::string& filename) const;
};

int check_key(const std::string& key);
#endif

