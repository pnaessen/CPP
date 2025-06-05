/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:33:50 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/05 17:30:23 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

	#include "Bureaucrat.hpp"
	class Bureaucrat;
	
	class Form {
		private:
			const std::string _name;
			bool _isSigned;
			const int _signGrade;
			const int _executeGrade;
			Form();
		public:
			Form(const std::string &name, int signGrade, int executeGrade);
			Form(const Form &obj);
			Form &operator=(const Form &obj);
			~Form();
			
			const std::string getName() const;
			bool getIsSigned() const;
			int getSignGrade() const;
			int getExecuteGrade() const;
			
			void beSigned(Bureaucrat &bureaucrat);
		
			
			class GradeTooHighE : public std::exception {
				public:
					const char *what() const throw() {
						return "Form grade too high";
					}
			};
			
			class GradeTooLowE : public std::exception {
				public:
					const char *what() const throw() {
						return "Form grade too low";
					}
			}; 
};

std::ostream& operator<<(std::ostream& o,const  Form& Form);
#endif