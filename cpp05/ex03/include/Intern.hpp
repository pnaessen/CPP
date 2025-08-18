/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:27:56 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/18 08:34:20 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

	#include "AForm.hpp"
	
	class Intern {
		private:
			Intern(Intern& obj);
			Intern &operator=(const Intern &obj);
		public:
			Intern();
			~Intern();

		
			AForm* makeForm(const std::string& formName, const std::string& target);
			
		class FormNotFoundException : public std::exception {
			public:
				const char *what() const throw();
		};

	};

#endif