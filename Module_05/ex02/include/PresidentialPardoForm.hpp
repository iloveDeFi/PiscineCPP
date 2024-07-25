/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardoForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:55:50 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/25 10:11:48 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardoForm : public AForm {
    
    private:
        std::string _target;

    public:
        PresidentialPardoForm(const std::string &target);
        PresidentialPardoForm(const PresidentialPardoForm &src);
        PresidentialPardoForm& operator=(const PresidentialPardoForm &src);
        ~PresidentialPardoForm();

        void execute(const Bureaucrat &executor) const;
};

#endif