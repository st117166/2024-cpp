#include <iostream>
#include <string>
#include <vector>

class BankAccount {
private:
	std::string accountNumber;
	double balance;
	std::string accountHolder;
public:
	BankAccount(std::string accountNumber, double balance, std::string accountHolder) : accountNumber(accountNumber), balance(balance), accountHolder(accountHolder) {}
	void Deposit(double amount);
	void Withdraw(double amount);
	double GetBalance() const;
	std::string GetAccountHolder() const;
	std::string GetAccountNumber() const;
	void PrintAccountInfo() const;
};

class Bank
{
private:
	std::vector<BankAccount> accounts;
public:
	void AddAccount(BankAccount account);
	double GetTotalBalance() const;
	void PrintAllaccounts() const;
};