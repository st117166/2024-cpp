#include <iostream>
#include <string>
#include <vector>

class BankAccount {
private:
	std::string accountNumber;
	double balance;
	std::string accountHolder;
public:
	BankAccount(std::string accountNumber, double balance, std::string accountHolder) : accountNumber(accountNumber), balance(balance), accountHolder(accountHolder) {
		this->accountNumber = accountNumber;
		this->balance = balance;
		this->accountHolder = accountHolder;
	}
	void Deposit(double amount)
	{
		balance += amount;
		std::cout << balance << std::endl;
	}
	void Withdraw(double amount)
	{
		if (amount > balance)
		{
			std::cout << "Ошибка: недостаточно средств" << std::endl;
		}
		else
		{
			balance -= amount;
			std::cout << balance << std::endl;
		}
	}
	double GetBalance() const
	{
		return balance;
	}
	std::string GetAccountHolder() const
	{
		return accountHolder;
	}
	std::string GetAccountNumber() const
	{
		return accountNumber;
	}
	void PrintAccountInfo() const
	{
		std::cout << "Номер счёта" << accountNumber;
		std::cout << "Текущий баланс счёта" << balance;
		std::cout << "Имя владельца счёта" << accountHolder;
	}
};

class Bank
{
private:
	std::vector<BankAccount> accounts;
public:
	void AddAccount(BankAccount account)
	{
		accounts.push_back(account); 
	}
	double GetTotalBalance() const
	{
		double totalBalance = 0;
		for (auto& account : accounts)
		{
			totalBalance += account.GetBalance();
		}
		return totalBalance;
	}
	void PrintAllaccounts() const
	{
	    for (auto& account : accounts)
		{
			account.PrintAccountInfo();
		}
		std::cout << " " << std::endl;
	}
};

int main(int argc, char* argv[])
{
	BankAccount account1("8594357845", 500000.0, "Вера");
	BankAccount account2("3567589234", 95670.89, "Настя");
	BankAccount account3("9483536789", 100500.56, "Милана");
	Bank bank;
	bank.AddAccount(account1);
	bank.AddAccount(account2);
	bank.AddAccount(account3);
	account1.Deposit(5000.0);
	account2.Withdraw(100000.86);
	account2.GetBalance();
	account3.GetAccountHolder();
	std::cout << "Информация обо всех счетах" << std::endl;
	bank.PrintAllaccounts();
	std::cout << "Общий баланс всех счетов" << bank.GetTotalBalance() << std::endl;

	return 0;
}