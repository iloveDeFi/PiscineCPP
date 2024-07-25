/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:59:12 by bat               #+#    #+#             */
/*   Updated: 2024/07/25 10:55:20 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {

    private :
        const std::string _name;
        int _grade;
    public:
	
		class GradeTooHighException : public std::exception {
		public :
			virtual const char* what() const throw() {
				return ("Grade is too HIGH.");
			}
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Grade is too LOW.");
				}
		};
		
        // Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat& operator=(const Bureaucrat &src);
        ~Bureaucrat(void);
		
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
		void signForm(AForm &aform) const;
        
        void executeForm(AForm const &aform) const;
};

std::ostream& operator<<(std::ostream &o, Bureaucrat const &other);

#endif