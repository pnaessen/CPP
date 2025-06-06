/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:33:50 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/06 16:57:02 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

	#include "Bureaucrat.hpp"
	class Bureaucrat;
	
	class AForm {
		private:
			const std::string _name;
			bool _isSigned;
			const int _signGrade;
			const int _executeGrade;
			AForm();
		public:
			AForm(const std::string &name, int signGrade, int executeGrade);
			AForm(const AForm &obj);
			AForm &operator=(const AForm &obj);
			virtual ~AForm() = 0;
			
			const std::string getName() const;
			bool getIsSigned() const;
			int getSignGrade() const;
			int getExecuteGrade() const;
			
			void beSigned(Bureaucrat &bureaucrat);
			virtual void execute(const Bureaucrat &executor) const;
		
			
			class GradeTooHighException : public std::exception {
				public:
					const char *what() const throw() {
						return "Form grade too Hight";
					}
			};
			
			class GradeTooLowException : public std::exception {
				public:
					const char *what() const throw() {
						return "Form grade too Low";
					}
			};
			
			class FormNotSignedException : public std::exception {
				public :
					const char *what() const throw() {
						return "Form not sign";
					}
			};
};

std::ostream& operator<<(std::ostream& o,const  AForm& Form);

#endif