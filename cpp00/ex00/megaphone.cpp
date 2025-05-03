/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:07:30 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/03 13:25:51 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	
	for (int i = 1; i < argc; i++) 
	{
		for (int x = 0; argv[i][x]; x++)
			std::cout << (char) toupper(argv[i][x]);
	}
	std::cout << std::endl;
	return (0);
}