/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:47:53 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/02 14:20:52 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    
    Bitcoin exchange;
    
    if (!exchange.loadDB("data.csv")) {
        return 1;
    }
    
    if (!exchange.processInput(argv[1])) {
        return 1;
    }
    
    return 0;
}