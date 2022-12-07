#include "helpers.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <map>

namespace LegacyCode
{
	double avg(const int* data, int size)
	{
		assert(size >= 0);

		double sum = 0.0;

		for (const int* ptr_item = data; ptr_item != data + size; ++ptr_item)
			sum += *ptr_item;

		return sum / size;
	}

	double avg(const int* begin, const int* end)
	{
		assert(begin != end);  // array cannot be empty

		double sum = 0.0;

		for (const int* ptr_item = begin; ptr_item != end; ++ptr_item)
			sum += *ptr_item;

		return sum / (end - begin);
	}

	const int* find(const int* begin, const int* end, int value)
	{
		for (const int* ptr_item = begin; ptr_item != end; ++ptr_item)
			if (*ptr_item == value)
				return ptr_item;
		return end;
	}	

	const int* find_if(const int* begin, const int* end, bool (*predicate)(int))
	{
		for (const int* ptr_item = begin; ptr_item != end; ++ptr_item)
			if (predicate(*ptr_item))
				return ptr_item;
		return end;
	}
}

namespace ModernCpp
{
	// TODO: Modernize avg function

	template <typename TIterator, typename TValue>
	TIterator find(TIterator begin, TIterator end, TValue value)
	{
		for (auto ptr_item = begin; ptr_item != end; ++ptr_item)
			if (*ptr_item == value)
				return ptr_item;
		return end;
	}

	template <typename TIterator, typename TPredicate>
	TIterator find_if(TIterator begin, TIterator end, TPredicate predicate)
	{
		for (auto it = begin; it != end; ++it)
			if (predicate(*it))
				return it;
		return end;
	}

	template <typename TContainer>
	void print(const TContainer& container, const std::string& prefix = "values")
	{
		std::cout << prefix << ": [ ";
		for (const auto& item : container)
			std::cout << item << " ";
		std::cout << "]\n";
	}

}

void foo()
{
	std::cout << "foo()\n";
}

bool is_even(int n)
{
	return n % 2 == 0;
}

void pointers_to_function()
{
	int* ptr_int = nullptr; // pointer to data
	
	void(*ptr_fun)() = foo;
	ptr_fun(); // foo()

	bool (*predicate)(int) = is_even;

	assert(predicate(4) == true);
	assert(predicate(5) == false);
}

namespace Explain
{
	template <typename T, uint32_t Size>
	void print(T(&tab)[Size])
	{
		for (uint32_t i = 0; i < Size; ++i)
			std::cout << "printing:" << tab[i] << "\n";
	}

	template <typename T, uint32_t Size>
	T* begin(T(&tab)[Size])
	{
		return tab;
	}

	template <typename T, uint32_t Size>
	T* end(T(&tab)[Size])
	{
		return tab + Size;
	}
}

bool gt_than_100(int n)
{
	return n > 100;
}

int main()
{	
	char tab1[10] = {};

	Explain::print(tab1);

	const int size = 10;
	int oldschool_data[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < size; ++i)
		std::cout << oldschool_data[i] << "\n";

	for (int i = 0; i < size; ++i)
		std::cout << *(oldschool_data + i) << "\n";

	Helpers::print(oldschool_data, "oldschool_data");
	std::cout << "avg: " << LegacyCode::avg(oldschool_data, size) << "\n";


	std::cout << "avg with pointers: "
		<< LegacyCode::avg(oldschool_data, oldschool_data + size) << "\n";

	const int* pos = LegacyCode::find(oldschool_data, oldschool_data + size, 42);

	if (pos != oldschool_data + size)
	{
		std::cout << "Found: " << *pos << "\n";
	}
	else
	{
		std::cout << "Value not found!\n";
	}

	//////////////////////////////////////
	// iterators

	std::cout << "\n------------------------------\n";

	std::vector<int> data = { 45, 345, 77, 45, 756, 876, 23, 55, 6, 66 };

	std::vector<int>::iterator it = data.begin(); // returns iterator to first item in container

	std::cout << "First item: " << *it << "\n";
	++it;
	std::cout << "Second item: " << *it << "\n";

	// classic loop with itertors
	for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
	{
		std::cout << "Item: " << *it << "\n";
	}

	std::cout << "\n------------------------------\n";

	//modern loop with iterators
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		std::cout << "Item: " << *it << "\n";
	}

	std::cout << "\n------------------------------\n";

	// most convinient modern loop
	for (const auto& item : data)
	{
		std::cout << "Item: " << item << "\n";
	}

	std::cout << "\n------------------------------\n";

	// is interpreted by compiler as
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		const auto& item = *it;
		std::cout << "Item: " << item << "\n";
	}

	std::cout << "\n------------------------------\n";

	for (auto it = data.rbegin(); it != data.rend(); ++it)
	{
		std::cout << "-> " << *it << "\n";
	}

	////////////////////////////////////////////
	// using generic find

	std::vector<std::string> words = { "weak up", "now", "sleep", "coffee", "break" };

	auto where_pos_right = ModernCpp::find(words.rbegin(), words.rend(), "now");

	if (where_pos_right != words.rend())
	{
		std::cout << "Found: " << *where_pos_right << "\n";
	}
	else
	{
		std::cout << "Word not found!\n";
	}

	auto where_pos_left = ModernCpp::find(words.begin(), words.end(), "now");
	if (where_pos_left != words.end())
	{
		std::cout << "Found: " << *where_pos_left << "\n";
	}

	if (--(where_pos_right.base()) != where_pos_left) // conversion requires --
	{
		std::cout << "Found different objects\n";
	}
	else
	{
		std::cout << "Word is the same\n";
	}

	pointers_to_function();

	std::cout << "\n-----------------------------------\n";

	////////////////////////
	// old style find_if

	int numbers[] = { 1, 3, 5, 7, 42, 77, 665, 22, 12, 6, 9 };

	const int* pos_even = LegacyCode::find_if(Explain::begin(numbers), Explain::end(numbers), is_even);

	if (pos_even != std::end(numbers))
	{
		std::cout << "Found even: " << *pos_even << "\n";
	}

	///////////////////////
	// modern find_if

	std::vector<int> vec_numbers = { 111, 34, 445, 7, 42, 77, 665, 22, 12, 6, 9 };

	auto it_even = 
		ModernCpp::find_if(std::begin(vec_numbers), std::end(vec_numbers), is_even);

	if (it_even != std::end(vec_numbers))
	{
		std::cout << "Found even: " << *it_even << "\n";
	}

	auto pred_gt_100 = [](int n) { return n > 100; };

	assert(pred_gt_100(200));
	assert(pred_gt_100(20) == false);

	auto it_gt_100 =
		ModernCpp::find_if(std::begin(vec_numbers), std::end(vec_numbers), pred_gt_100);

	if (it_even != std::end(vec_numbers))
	{
		std::cout << "Found >100: " << *it_gt_100 << "\n";
	}

	std::cout << "No of evens: " << std::count_if(vec_numbers.begin(), vec_numbers.end(), is_even) << "\n";

	std::sort(vec_numbers.begin(), vec_numbers.end());

	ModernCpp::print(vec_numbers, "vec_numbers sorted");

	std::sort(vec_numbers.begin(), vec_numbers.begin() + (vec_numbers.size() / 2), [](int a, int b) { return a > b; });

	ModernCpp::print(vec_numbers, "vec_numbers sorted desc");

	///////////////////////////////////
	// inserters
	std::vector<std::string> words2 = { "one", "!two", "three", "!four", "five" };
	std::vector<std::string> backup(words2.size());

	std::copy(words2.begin(), words2.end(), backup.begin());
	
	std::vector<std::string> exclamations{};

	auto pusher = std::back_inserter(exclamations);
	*pusher = "!!!"; // exclamations.push_back("!!!")
	*pusher = "!!!Hohoho"; // exclamations.push_back("!!!Ho ho ho")

	std::copy_if(words2.begin(), words2.end(), std::back_inserter(exclamations),
		[](const std::string& word) { return word.at(0) == '!'; });

	ModernCpp::print(exclamations, "!!!");

	std::sort(std::begin(numbers), std::end(numbers));
	std::sort(std::begin(vec_numbers), std::end(vec_numbers));
	ModernCpp::print(numbers, "numbers");
	ModernCpp::print(vec_numbers, "vec_numbers");

	std::vector<int> merged_data(std::size(numbers) + vec_numbers.size());
	
	std::merge(std::begin(numbers), std::end(numbers),
		std::begin(vec_numbers), std::end(vec_numbers),
		merged_data.begin());

	ModernCpp::print(merged_data, "merged_data");

	std::vector<std::string> v_cities = { "krk", "waw", "kwi", "krk", "waw" };
	std::map<std::string, int> m_city_population = { { "krk", 1'000'000}, {"waw", 3'000'000}, {"kwi", 50'000} };

	std::vector<int> populations(v_cities.size());
	
	std::transform(v_cities.begin(), v_cities.end(), populations.begin(),
		[&m_city_population](const std::string& city) { return m_city_population.at(city); });

	ModernCpp::print(populations, "pops");
}