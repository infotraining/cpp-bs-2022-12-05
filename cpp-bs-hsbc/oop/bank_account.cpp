#include "bank_account.hpp"

std::ostream& Banking::operator<<(std::ostream& out, const Transaction& t)
{
	char transaction_char = static_cast<char>(t.type);
	out << "id: " << t.account_id
		<< ", transaction type: " << transaction_char
		<< " - " << transaction_dict.at(transaction_char)
		<< ", amount: " << t.amount << "\n";

	return out;
}

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

inline void Banking::BankAccount::withdraw(double amount)
{
	//assert(amount >= 0);
	check_amount(amount);
	balance_ -= amount;
	transactions_.push_back(
		Transaction{ id_, TransactionsType::withdrawal, amount });
}

inline void Banking::BankAccount::deposit(double amount)
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
		std::terminate();
	}
}
