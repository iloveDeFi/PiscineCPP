/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:53:14 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/23 11:10:02 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form(void);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form(void);

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
		void beSigned(const Bureaucrat &bureaucrat);
        
		class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too high!";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too low!";
                }
        };
};

std::ostream& operator<<(std::ostream &o, Form const &other);

#endif
