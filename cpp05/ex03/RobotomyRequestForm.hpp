/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:38:46 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/06 15:55:15 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
	
	#include "AForm.hpp"
	#include "Bureaucrat.hpp"
	#include  <cstdlib>
	
	class RobotomyRequestForm : public AForm {
		private :
			RobotomyRequestForm();
			std::string _target;

		public :
			RobotomyRequestForm(const std::string &target);
			RobotomyRequestForm(const RobotomyRequestForm& obj);
			RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
			virtual ~RobotomyRequestForm();
			
			void execute(Bureaucrat const &executor) const;
			
};

#endif

