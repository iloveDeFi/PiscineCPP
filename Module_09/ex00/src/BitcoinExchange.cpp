#include "BitcoinExchange.hpp"

btc::btc() {

}

btc::~btc() {

}

btc::btc(const btc & src) : _btcData(src._btcData) {

}

btc& btc::operator=(const btc & src) {
    if (this != &src) {
        this->_btcData = src._btcData;
    }
    return (*this);
}