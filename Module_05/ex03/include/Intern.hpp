/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:39 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/29 15:24:46 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>

class Intern {

    private :
    	AForm	*makeSCF(std::string target) const;
		AForm	*makePPF(std::string target) const;
		AForm	*makeRRF(std::string target) const;

    public :

        Intern();
        Intern(const Intern &intern);
        Intern& operator=(const Intern &intern);
        ~Intern();
        
        AForm* makeForm(const std::string formName, const std::string &target) const;

        class FormDoesntExist : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Form name passed doesn't exist sorry mister universe.");
				}
		};
};

#endif