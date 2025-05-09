/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:50:03 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/09 09:42:26 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;
	
	if(argc != 2) {
		std::cout << "Error Bad arg" << std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}