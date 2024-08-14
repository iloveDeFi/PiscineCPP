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
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class btc {
    private:
        std::map<std::string, float> _btcData;
        static bool isValidDate(const std::string& date);

    public:
        // load data from my csv
        btc(const std::string& filename);
        ~btc();
        btc(const btc & src);
        btc& operator=(const btc & src);

        float getValue(const std::string& date) const;
        void csvLoadData();
        static std::string trim(const std::string& str);
};

#endif

