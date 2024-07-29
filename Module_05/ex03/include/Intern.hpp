/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:39 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/26 10:21:41 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <stdexcept>

class AForm;

class Intern {
    public :

        Intern();
        Intern(const Intern &intern);
        Intern& operator=(const Intern &intern);
        ~Intern();
        
        Form* makeForm(const std::string formName, std::string &target const);


        class FormDoesntExist : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Form name passed doesn't exist sorry.");
				}
		};
};

#endif