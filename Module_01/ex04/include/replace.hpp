/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:52:29 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 14:46:17 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

class Replace {
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
         // Methods setters and getters
        std::string readInputFile() const;
        void writeOutputFile(const std::string& content) const;
        std::string replaceOccurences(const std::string& content) const;


    public:
        // Construct
        Replace(const std::string& filename, const std::string& s1,
            const std::string& s2);
        // Destruct
        ~Replace();
        // Methods setters and getters
        void launchReplacement() const;
};

#endif