/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:59:12 by bat               #+#    #+#             */
/*   Updated: 2024/07/20 16:11:02 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
    private :
        const std::string name;
        // 1 is highet and 150 lowest
        int grade;
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat(void);
        void getName() const;
        void getGrade() const;
        void increGrade();
        void decreGrade();
};

You will provide an overload of the <<operator to ostream that outputs something
like <name>, bureaucrat grade <grade>

#endif