#include "primes.hpp"
#include <cmath>
#include <vector>

bool MyMath::is_prime(uint64_t n)
{
	for (uint64_t i = 2; i <= std::sqrt(n); ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

std::vector<uint64_t> MyMath::primes(uint64_t n)
{
	std::vector<uint64_t> found_primes;

	for (uint64_t i = 2; i <= n; ++i)
		if (is_prime(i))
			found_primes.push_back(i);

	return found_primes;
}