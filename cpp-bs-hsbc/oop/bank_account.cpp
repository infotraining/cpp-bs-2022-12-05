#include "bank_account.hpp"

bool Banking::Transaction::operator==(const Transaction& right) const
{
	return (account_id == right.account_id)
		&& (type == right.type)
		&& (amount == right.amount);
}

bool Banking::Transaction::operator!=(const Transaction& right) const
{
	return !(*this == right);
}

void Banking::Transaction::print() const
{
	char transaction_char = static_cast<char>(type);
	std::cout << "id: " << this->account_id
		<< ", transaction type: " << transaction_char
		<< " - " << transaction_dict.at(transaction_char)
		<< ", amount: " << amount << "\n";
}

void Banking::BankAccount::withdraw(double amount)
{
	//assert(amount >= 0);
	check_amount(amount);
	balance_ -= amount;
	transactions_.push_back(
		Transaction{ id_, TransactionsType::withdrawal, amount });
}

void Banking::BankAccount::deposit(double amount)
{
	//assert(amount >= 0);
	check_amount(amount);
	balance_ += amount;
	transactions_.push_back(
		Transaction{ id_, TransactionsType::deposit, amount });
}

inline void Banking::BankAccount::check_amount(double amount)
{
	if (amount < 0)
	{
		std::string desc = "Account#" + std::to_string(id_);
		throw std::invalid_argument(desc + "; Amount < 0.0");
	}
}
