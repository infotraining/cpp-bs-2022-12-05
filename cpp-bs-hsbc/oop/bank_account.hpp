#pragma once

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <cassert>
#include <exception>

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

		void print() const;

		bool operator==(const Transaction& right) const;		
		bool operator!=(const Transaction& right) const;		
		
		// bool operator==(const Transaction& right) const = default;  // C++20 - near future

		friend std::ostream& operator<<(std::ostream& out, const Transaction& t)
		{
			char transaction_char = static_cast<char>(t.type);
			out << "id: " << t.account_id
				<< ", transaction type: " << transaction_char
				<< " - " << transaction_dict.at(transaction_char)
				<< ", amount: " << t.amount;

			return out;
		}
	};	

	//bool operator==(const Transaction& left, const Transaction& right)
	//{
	//	return (left.account_id == right.account_id)
	//		&& (left.type == right.type)
	//		&& (left.amount == right.amount);
	//}

	class BankAccount
	{
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

		void withdraw(double amount);

		void deposit(double amount);

		double check()
		{
			balance_ -= check_fee_;
			transactions_.push_back(Transaction{ id_, TransactionsType::check, check_fee_ });
			return balance_;
		}

		const std::vector<Transaction>& transactions() const
		{
			return transactions_;
		}		

		static void set_check_fee(double fee)
		{
			check_fee_ = fee;
		}
	private:
		const uint64_t id_ = 0;
		std::string owner_ = "";
		double balance_ = 0.0;
		inline static double check_fee_ = 1.0;
		std::vector<Transaction> transactions_;

		void check_amount(double amount);
	};
}

