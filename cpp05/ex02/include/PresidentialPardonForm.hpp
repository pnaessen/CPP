/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:09:50 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/23 09:33:11 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

	#include "AForm.hpp"
	#include "Bureaucrat.hpp"

	class PresidentialPardonForm : public AForm {
		private:
			std::string _target;
			PresidentialPardonForm();
		public:
			PresidentialPardonForm(const std::string &target);
			PresidentialPardonForm(const PresidentialPardonForm &obj);
			PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
			virtual ~PresidentialPardonForm();

			void executeForm() const;
};



#endif