#include <string>
#include <iostream>
#include <vector>
#include "bank_account.hpp"

int main()
{
	using namespace Banking;

	const Transaction t1{ 665, TransactionsType::deposit, 100.0 };
	t1.print();

	std::vector<Transaction> vec_trans = { t1, {777, TransactionsType::check, 1'000'000} };
	vec_trans.push_back(Transaction{ 432, TransactionsType::withdrawal, 3'000'000 });

	vec_trans[0].amount = 1'000'099;
	vec_trans[0].print();

	for (const auto& t : vec_trans)
		t.print();

	std::cout << t1 << "\n";
}