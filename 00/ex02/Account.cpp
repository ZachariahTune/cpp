#include <iostream>
#include <ctime>
#include "Account.hpp"

//Стартовые значения статичных переменных
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//Конструктор
Account::Account(int initial_deposit)
{
	//Значения переменных класса
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	//Вывод на экран
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

//Деструктор
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

//Вывод текущей даты в скобках
void	Account::_displayTimestamp(void)
{
	time_t		now = time(0);
	struct tm	tstruct;
	char		buf[16];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tstruct);
	std::cout << "[" << buf << "] ";
}

//Вывод общей информации по всем аккаунтам
void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

//Вывод статуса отдельного аккаунта
void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

//Увеличение состояния счета
void	Account::makeDeposit(int deposit)
{
	//Изменение значений переменных
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	//Вывод на экран
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << (this->_amount - deposit) << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

//Уменьшение состояния счета
bool	Account::makeWithdrawal(int withdrawal)
{
	int	withdrawal_ok = 0;

	//Изменение значений переменных
	if (this->_amount >= withdrawal)
	{
		withdrawal_ok = 1;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
	}
	//Вывод на экран
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	if (withdrawal_ok == 0)
	{
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	if (withdrawal_ok == 1)
	{
		std::cout << "p_amount:" << (this->_amount + withdrawal) << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
	}
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}
