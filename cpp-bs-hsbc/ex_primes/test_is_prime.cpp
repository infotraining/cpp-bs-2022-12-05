#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cstdint>
#include <cmath>
#include <vector>
#include "primes.hpp"

TEST_CASE("is_prime")
{	
	using namespace MyMath;

	REQUIRE(is_prime(2));
	REQUIRE(is_prime(3));
	REQUIRE_FALSE(is_prime(4));
	REQUIRE(is_prime(5));
	REQUIRE_FALSE(is_prime(6));
	REQUIRE(is_prime(13));
	REQUIRE_FALSE(is_prime(14));
	REQUIRE(is_prime(59));
	REQUIRE(is_prime(997));
}
