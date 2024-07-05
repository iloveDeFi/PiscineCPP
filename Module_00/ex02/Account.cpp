/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:23:59 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/05 12:19:20 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// CONSTRUCTOR
Account::Account(int initialDeposit)
    : _accountIndex(_nbAccounts),
      _amount(initialDeposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initialDeposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
}

// DESTRUCTOR
Account::~Account(){
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";closed" << std::endl;
}

// GETTERS
int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

// METHODS
void Account::_displayTimestamp() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec << "]";
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount 
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:"
			<< _totalNbWithdrawals << std::endl;
}

int Account::checkAmount() const { return _amount; }

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount 
		<< ";deposits:" << _nbDeposits << ";withdrawals:"
			<< _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount < withdrawal) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}
