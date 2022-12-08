#include "pch.h"
#include "CppUnitTest.h"
#include "..\oop\bank_account.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ooptests
{
	using namespace Banking;
	using namespace std::literals;

	TEST_CLASS(TransactionTests)
	{
	public:
		TEST_METHOD(Operator_Equals)
		{
			Transaction t1{ 1, TransactionsType::deposit, 100.0 };
			Transaction t2{ 1, TransactionsType::deposit, 100.0 };

			Assert::IsTrue(t1 == t2);
			Assert::IsTrue(t1.operator==(t2));
		}

		TEST_METHOD(Operator_NotEquals)
		{
			Transaction t1{ 1, TransactionsType::deposit, 100.0 };
			Transaction t2{ 1, TransactionsType::withdrawal, 100.0 };

			Assert::IsTrue(t1 != t2);
			Assert::IsTrue(t1.operator!=(t2));
		}
	};

	TEST_CLASS(BankAccountTests)
	{		
	public:

		//TEST_METHOD(Default_Constructor)
		//{
		//	BankAccount ba;

		//	Assert::AreEqual(ba.id(), 0ull);
		//	Assert::AreEqual(ba.owner(), ""s);
		//	Assert::AreEqual(ba.balance(), 0.0);
		//}
		
		TEST_METHOD(Create_Bank_Account)
		{
			BankAccount ba{ 665, "Jan Kowalski", 1'000 };			

			Assert::AreEqual(ba.id(), 665ull);
			Assert::IsTrue(ba.owner() == "Jan Kowalski"s);
			Assert::AreEqual(ba.balance(), 1'000.0);
		}

		TEST_METHOD(Withdraw)
		{
			// Arrange
			BankAccount ba{ 665, "Jan Kowalski", 1'000 };
			//Assert::AreEqual(ba.transactions().size(), 0ull);

			// Act
			ba.withdraw(100.0);

			// Assert
			Assert::AreEqual(ba.balance(), 900.0);
			//Assert::AreEqual(ba.transactions().size(), 1ull);
			Assert::IsTrue(ba.transactions().back()
				== Transaction{ 665, TransactionsType::withdrawal, 100.0 });
		}

		TEST_METHOD(Deposit)
		{
			// Arrange
			BankAccount ba{ 665, "Jan Kowalski", 1'000 };
			
			// Act
			ba.deposit(-500.0);

			// Assert
			Assert::AreEqual(ba.balance(), 1'500.0);
			Assert::IsTrue(ba.transactions().back() 
				== Transaction{ 665, TransactionsType::deposit, 500.0 });
		}
	};
}
