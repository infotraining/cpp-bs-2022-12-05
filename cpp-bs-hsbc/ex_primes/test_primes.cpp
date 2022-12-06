#include "catch.hpp"
#include "primes.hpp"
#include <vector>
#include <iostream>
#include <set>

TEST_CASE("find all primes in range [2;n]")
{
	// uncomment lines below 
	using namespace MyMath;
	
	REQUIRE((primes(10) == std::vector<uint64_t>{ 2, 3, 5, 7 }));
	REQUIRE((primes(20) == std::vector<uint64_t>{2, 3, 5, 7, 11, 13, 17, 19}));

	REQUIRE((primes(20) == std::vector<uint64_t>{2, 4, 5, 7, 11, 13, 17, 19}));
}

TEST_CASE("set & multiset")
{
	std::set<int> unique_numbers = { 1, 1, 1, 5, 745, 23, 65, 645, 65, 345, 346, 1, 3 };

	unique_numbers.insert(777);
	unique_numbers.insert(75);
	unique_numbers.insert(1);	

	for (const auto& item : unique_numbers)
		std::cout << item << " ";
	std::cout << "\n";
}