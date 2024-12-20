#include "bank.h"

BankAccount::BankAccount(std::string accountNumber, double balance, std::string accountHolder) : accountNumber(accountNumber), balance(balance), accountHolder(accountHolder) {
	this->accountNumber = accountNumber;
	this->balance = balance;
	this->accountHolder = accountHolder;
}
void BankAccount::Deposit(double amount)
{
	balance += amount;
	std::cout << balance << std::endl;
}
void BankAccount::Withdraw(double amount)
{
	if (amount > balance)
	{
		std::cout << "Insuffficient funds for withdrawal" << std::endl;
	}
	else
	{
		balance -= amount;
		std::cout << balance << std::endl;
	}
}
double BankAccount::GetBalance() const
{
	return balance;
}
std::string BankAccount::GetAccountHolder() const
{
	return accountHolder;
}
std::string BankAccount::GetAccountNumber() const
{
	return accountNumber;
}
void BankAccount::PrintAccountInfo() const
{
	std::cout << "Account Number" << accountNumber;
	std::cout << "Balance" << balance;
	std::cout << "Account Holder" << accountHolder;
}

void Bank::AddAccount(BankAccount account)
{
		accounts.push_back(account);
}
double Bank::GetTotalBalance() const
{
	double totalBalance = 0;
	for (auto& account : accounts)
	{
		totalBalance += account.GetBalance();
	}
	return totalBalance;
}
void Bank::PrintAllaccounts() const
{
	for (auto& account : accounts)
	{
		account.PrintAccountInfo();
	}
	std::cout << " " << std::endl;
}