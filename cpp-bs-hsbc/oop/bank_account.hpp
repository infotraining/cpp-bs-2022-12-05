#pragma once

#include <string>
#include <map>
#include <iostream>
#include <vector>

namespace Banking
{
	enum class TransactionsType : char { withdrawal = 'W', deposit = 'D', check = 'C' };

	const std::map<char, std::string> transaction_dict = { 
		{'W', "withdrawal"}, 
		{'D', "deposit"},
		{'C', "check"} 
	};

	struct Transaction
	{
		uint64_t account_id;
		TransactionsType type;
		double amount;

		void print() const
		{
			char transaction_char = static_cast<char>(type);
			std::cout << "id: " << this->account_id
				<< ", transaction type: " <<  transaction_char
				<< " - " << transaction_dict.at(transaction_char)
				<< ", amount: " << amount << "\n";
		}
	};

	class BankAccount
	{
		const uint64_t id_ = 0;
		std::string owner_ = "";
		double balance_ = 0.0;
		std::vector<Transaction> transactions_;
	public:
		//// default constructor
		//BankAccount() = default;

		//// constructor
		BankAccount(uint64_t id, const std::string& owner, double balance = 0.0)
			: id_(id), owner_{owner}, balance_{balance} // init list for constructor
		{						
		}

		uint64_t id() const
		{
			return this->id_;
		}

		std::string owner() const
		{
			return owner_;
		}

		double balance() const
		{
			return balance_;
		}

		void withdraw(double amount)
		{
			balance_ -= amount;
			transactions_.push_back(
				Transaction{ id_, TransactionsType::withdrawal, amount });
		}

		const std::vector<Transaction>& transactions() const
		{
			return transactions_;
		}
	};
}

