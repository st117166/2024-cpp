#include <gtest/gtest.h>
#include "bank.h"
#include "bank.cpp"

class BankAccountTest : public testing::Test
{
protected:
	BankAccount account{ "1858967", 15000.0, "Ivan Ivanov" };
};

class BankTest : public testing::Test 
{
protected:
	Bank bank;
	BankAccount account1 {"1858967", 15000.0, "Ivan Ivanov" };
	BankAccount account2{ "2456789", 20000.0, "Valeria Volkova"};
	void SetUp()
	{
		bank.AddAccount(account1);
		bank.AddAccount(account2);
	}
};

TEST_F(BankAccountTest, Initialization)
{
	EXPECT_EQ(account.GetAccountNumber(), "1858967");
	EXPECT_EQ(account.GetBalance(), 15000.0);
	EXPECT_EQ(account.GetAccountHolder(), "Ivan Ivanov");
}

TEST_F(BankAccountTest, Deposit)
{
	account.Deposit(50000.0);
	EXPECT_EQ(account.GetBalance(), 65000.0);
}

TEST_F(BankAccountTest, WithdrawExceedingBalance)
{
	double currentBalance = account.GetBalance();
	account.Withdraw(100000.0);
	EXPECT_EQ(account.GetBalance(), currentBalance);
}

TEST_F(BankAccountTest, WithdrawDecreaseBalance)
{
	account.Withdraw(10000.0);
	EXPECT_EQ(account.GetBalance(), 5000.0);
}
TEST_F(BankTest, TotalBalance)
{
	EXPECT_EQ(bank.GetTotalBalance(), 35000);
}

TEST_F(BankAccountTest, DepositBalance)
{
	double currentbalance = account.GetBalance();
	account.Deposit(1000.0);
	ASSERT_TRUE(account.GetBalance() > currentbalance);
}

TEST_F(BankAccountTest, Withdraw)
{
	double currentbalance = account.GetBalance();
	account.Withdraw(1000.0);
	ASSERT_TRUE(account.GetBalance() < currentbalance);
}

TEST_F(BankAccountTest, InitialBalance)
{
	ASSERT_FALSE(account.GetBalance() < 0);
}