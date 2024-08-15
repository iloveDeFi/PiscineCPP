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
#include <map>


class btc {
    private:
        std::string _filename;
        std::map<std::string, float> _exchangeRates;

        

    public:
        // load data from my csv
        btc(const std::string& filename);
        ~btc();
        btc(const btc & src);
        btc& operator=(const btc & src);

        void loadExchangeRates(const std::string& dataFile);
        float getExchangeRate(const std::string& date) const;

        static std::string trim(const std::string& str);
        static bool isValidDate(const std::string& date);
};

#endif

