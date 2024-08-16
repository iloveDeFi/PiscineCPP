/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:40:37 by bbessard          #+#    #+#             */
/*   Updated: 2024/08/14 17:20:56 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
# define BTC_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>
#include <map>

class btc {
    private:
        std::string _filename;
        std::map<std::string, float> _exchangeRates;

    public:
        btc(const std::string& filename);
        ~btc();
        btc(const btc & src);
        btc& operator=(const btc & src);

        void loadExchangeRates();
        float getExchangeRate(const std::string& date) const;
        void printData() const;
         int dateChecker(const std::string& date) const;
        // void printMap(const std::map<std::string, float>& _exchangeRates) const;

        const std::map<std::string, float>& getExchangeRates() const {
        return _exchangeRates;
    }

        static std::string trim(const std::string& str);
        static bool isValidDate(const std::string& date);
        
};

#endif

