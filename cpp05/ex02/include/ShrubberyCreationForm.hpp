/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:55:03 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/23 09:33:27 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

	#include <fstream>
	#include "AForm.hpp"
	#include "Bureaucrat.hpp"

	class ShrubberyCreationForm : public AForm {
		private:
			std::string _target;
			ShrubberyCreationForm();
		public:
			ShrubberyCreationForm(const std::string &target);
			ShrubberyCreationForm(const ShrubberyCreationForm &obj);
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
			virtual ~ShrubberyCreationForm();

			void executeForm() const;

};
	


#endif