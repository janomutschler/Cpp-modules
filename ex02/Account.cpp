/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:03:49 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/27 13:41:51 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.h"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t t = std::time(NULL);
    std::tm *lt = std::localtime(&t);
    std::cout << '['
              << (lt->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (lt->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << lt->tm_mday
              << '_'
              << std::setw(2) << std::setfill('0') << lt->tm_hour
              << std::setw(2) << std::setfill('0') << lt->tm_min
              << std::setw(2) << std::setfill('0') << lt->tm_sec
              << "]";
    std::cout << std::setfill(' ');
}


Account::Account( int initial_deposit )
{
	if (initial_deposit < 0)
	{
		_displayTimestamp();
		std::cout << "initial_deposit cant be negativ initial deposit will be adjusted to 0\n";
		_amount = 0;
	}
	else
		_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount = _totalAmount + _amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

int	Account::getNbAccounts() { return _nbAccounts; }
int	Account::getTotalAmount() { return _totalAmount; }
int	Account::getNbDeposits() { return _totalNbDeposits; }
int	Account::getNbWithdrawals() { return _totalNbWithdrawals; }

int Account::checkAmount() const { return _amount; }

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout 	<< " accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout 	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout 	<< " index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:";
	if (deposit <= 0)
	{
		std::cout << "refused\n";
		return ;
	}
	_amount = _amount + deposit;
	_nbDeposits++;
	
	_totalAmount = _totalAmount + deposit;
	_totalNbDeposits++;

	std::cout << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	
	std::cout 	<< " index:" << _accountIndex
				<< ";p_amount:" << _amount << ";withdrawal:";

	if (withdrawal <= 0 || withdrawal > _amount)
	{
		std::cout << "refused\n";
		return (false);
	}
	_amount = _amount - withdrawal;
	_nbWithdrawals++;
	
	_totalAmount = _totalAmount - withdrawal;
	_totalNbWithdrawals++;

	std::cout	<< withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return (true);
}

