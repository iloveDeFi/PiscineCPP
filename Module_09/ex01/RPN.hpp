/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:58:52 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/16 19:00:03 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>
#include <deque>

class RPN {
    private:
        std::string _filename;
        std::map<std::string, float> _exchangeRates;

    public:
        RPN(const std::string& filename);
        ~RPN();
        RPN(const RPN & src);
        RPN& operator=(const RPN & src);

        void loadExchangeRates();
        float getExchangeRate(const std::string& date) const;
        void printData() const;
         int dateChecker(const std::string& date) const;
        // void printMap(const std::map<std::string, float>& _exchangeRates) const;

        static std::string trim(const std::string& str);
        static bool isValidDate(const std::string& date);
        
};

#endif
