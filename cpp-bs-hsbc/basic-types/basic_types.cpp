#include <iostream>
#include <string>
#include <chrono>
#include <cassert>
#include <vector>
#include <array>
#include <map>

using namespace std::literals;

namespace Helpers
{
	void print_line(char c = '-', size_t length = 40)
	{
		for (size_t i = 0; i < length; ++i)
			std::cout << c;
		std::cout << "\n";
	}

	template <typename T1, typename T2>
	std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& p)
	{
		out << "{" << p.first << ", " << p.second << "}";
		return out;
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

int main()
{
	Helpers::print_line();
	std::cout << "Basic types in C++...\n";

	////////////////////////////////////////
	// integers
	int x = 42;
	int y{ 42 };
	std::cout << "sizeof(int): " << sizeof(int) << "\n";
	unsigned int ux = 42U;
	auto ax = 665U; // unsigned int

	unsigned int result = ux - 43;
	std::cout << "result: " << result << "\n";

	long lx = 10'000'000L;
	std::cout << "sizeof(long): " << sizeof(long) << "\n";

	long long llx = 1'000'000'000LL;
	std::cout << "sizeof(long long): " << sizeof(long long) << "\n";

	char c = 65;
	auto cplus1{ c + 1 };
	std::cout << "c: " << c << "\n";

	unsigned char uc = 66;
	std::cout << "uc: " << uc << "\n";

	int8_t small_number = 65;
	int32_t normal_numer = 665;
	uint64_t large_positive_number = 1'000'000'000;

	// safe init - narrowing conversion is an error
	intmax_t sum{ x + llx };

	int evil_x = -1;
	unsigned evil_y = 666;

	// beware - evil code
	if (evil_x < evil_y)
	{
		std::cout << "evil_x: " << evil_x << " < " << "evil_y:" << evil_y << "\n";
	}
	else
	{
		std::cout << "evil_x: " << evil_x << " >= " << "evil_y:" << evil_y << "\n";
	}

	////////////////////////////////////////
	// floating points
	float pi_fl = 3.1415f;
	std::cout << "sizeof(float): " << sizeof(float) << "\n";

	double pi_dl = 3.1415;
	std::cout << "sizeof(double): " << sizeof(double) << "\n";

	// float fl_value{ pi_dl }; // narrowing conversion - error

	double dx{}; // init with zero
	std::cout << "dx: " << dx << "\n";

	////////////////////////////////////////
	// boolean values
	bool logic_flag = true;
	logic_flag = false;

	if (logic_flag)
	{
		std::cout << "logic_flag is set to true\n";
	}

	if (!logic_flag)
	{
		std::cout << "logic_flag is set to false\n";
	}

	bool flag_a = true;
	bool flag_b = false;

	assert(flag_a && flag_b == false);  // assert(flag_a and flag_b == false);
	assert(flag_a || flag_b == false);  // assert(flag_a or flag_b == false);
	assert(!flag_b); // assert(not flag_b)


	////////////////////////////////////////
	// strings

	// legacy (old-school) text 
	const char* c_text1 = "Hello";
	assert(c_text1[1] == 'e');
	assert(strlen(c_text1) == 5);
	assert(c_text1 == "Hello"s);
	const char* c_text2 = "World";

	auto c_full_text = std::string(c_text1) + c_text2;

	std::cout << c_text1 << "\n";

	std::string str_text = "Hello";

	if (str_text == "Hello")
	{
		std::cout << str_text << " is " << "Hello" << "\n";
	}

	if (str_text > "hello")
	{
		std::cout << str_text << " > " << "hello" << "\n";
	}

	std::cout << "Length of str_text: " << str_text.size() << "\n";

	std::string full_text = str_text + " " + "world";

	auto a_text = "Hello"s;
	assert(a_text[1] == 'e');
	assert(a_text.size() == 5);

	////////////////////////////////////////
	// vector
	int native_array[5] = { 1, 2, 3, 4, 5 };
	std::array<int, 5> modern_array = { 1, 2, 3, 4, 5 };

	std::vector<int32_t> empty_data;
	assert(empty_data.size() == 0);

	int less_evil = 665;
	std::vector<double> data{ 1, 2, 3, 4, 5, 42.6, static_cast<double>(less_evil) };
	data.reserve(100);
	std::cout << "data.size() = " << data.size() << "\n";
	std::cout << "data.capacity() = " << data.capacity() << "\n";
	data[2] = 33;

	// legacy for-each
	for (size_t i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << " ";
	}

	std::cout << "\n";

	data.push_back(100);
	std::cout << "data.size() = " << data.size() << "\n";
	std::cout << "data.capacity() = " << data.capacity() << "\n";

	data.push_back(200);
	data.insert(data.begin(), 201);

	// modern for-each
	for (auto item : data)
	{
		std::cout << item << " ";
	}

	std::cout << "\n";

	Helpers::print_line();

	std::vector<int> vec1 = { 1, 2, 3, 4 };
	std::vector<int> vec2 = { 5, 6, 7, 8 };

	std::vector<int> vec3 = vec1;  // vec1 is copied to vec3
	vec3.insert(vec3.end(), vec2.begin(), vec2.end());

	std::cout << "vec3.size() = " << vec3.size() << "\n";
	std::cout << "vec3.capacity() = " << vec3.capacity() << "\n";

	Helpers::print(vec3, "vec3");
	
	////////////////////////////////////////
	// value types - value semantics
	int vx = 42;
	int vy = vx;
	
	std::string txt1 = "Text";
	std::string txt2 = txt1;
	txt1[0] = 't';

	std::cout << txt2 << "\n";

	const std::vector<std::string> words = { "one", "two", "three" };
	std::vector<std::string> backup_words = words; 

	for (auto& item : backup_words)
	{
		item += "!!!";
		std::cout << item << " ";
	}
	std::cout << "\n";

	for (auto item : backup_words)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";


	////////////////////////////////////////
	// reference types
	Helpers::print_line();

	int original_value = 665;
	int another_value = 42;
	int& ref_value = original_value; // binding 

	ref_value += 10;
	std::cout << "original_value: " << original_value << "\n";

	// beware!!!
	const std::string& one_word = words[0];
	const std::string* ptr_word = &words[0];
	auto pos = words.begin();

	//words.push_back("four"); // error - push_back illegal for const object

	//std::cout << one_word << "\n"; // UB
	//std::cout << *pos << "\n"; // UB
	//std::cout << *ptr_word << "\n"; // UB

	////////////////////////////////////////
	// pointer types	
	auto* ptr_int = &original_value;

	std::cout << "ptr_int: " << ptr_int << " -> " << *ptr_int << "\n";
	int target_value = *ptr_int;

	ptr_int = &another_value;
	std::cout << "ptr_int: " << ptr_int << " -> " << *ptr_int << "\n";

	int* another_ptr = nullptr;
	
	if (another_ptr != nullptr)
		std::cout << *another_ptr << "\n";

	// legacy code
	int raw_data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int* it = raw_data; it != raw_data + 10; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	{ // modern iteration
		for (const auto& item : raw_data)
		{
			std::cout << item << " ";
		}
	}

	///////////////////////////////////////////////
	// constants

	const int constant_value = 665;

	int value_mutable = 999;
	++value_mutable;

	const int& constref_value = value_mutable;

	std::map<std::string, const double> math_constants = { {"pi", 3.14}, { "e", 2.71 } };

	math_constants.insert(std::make_pair("thau", 1.61));

	system("PAUSE");
}