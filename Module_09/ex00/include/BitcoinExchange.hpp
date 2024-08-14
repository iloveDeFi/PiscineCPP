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
#include <iostream>
#include <map>

class btc {
    private:
        std::map<std::string, float> _btcData;

    public:
        btc();
        ~btc();
        btc(const btc & src);
        btc& operator=(const btc & src);

};

#endif