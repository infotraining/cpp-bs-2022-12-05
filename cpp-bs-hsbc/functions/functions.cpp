#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <complex>

namespace Hsbc
{
	namespace MyMath
	{
		int multiply(int x, int y);

		namespace Generic
		{
			template <typename T>
			auto multiply(T a, T b)
			{
				return a * b;
			}
		}

		int square(int x) // definition
		{
			return x * x;
		}

		double square(double d)
		{
			return d * d;
		}

		std::complex<double> square(std::complex<double> c)
		{
			return c * c;
		}

		namespace Generic
		{
			template <typename T>
			T square(T x)
			{
				return x * x;
			}

			double square(double x)
			{
				return x * x;
			}

			//namespace Cpp20
			//{
			//	auto square(auto x)
			//	{
			//		return x * x;
			//	}				
			//}
		}

		int multiply(int x, int y)
		{
			return x * y;
		}

		void print_line(char c = '-')
		{
			for (int i = 0; i < 40; ++i)
				std::cout << c;
			std::cout << "\n";
		}
	}

	namespace ByValue
	{
		int next(int n /*in*/)
		{
			return ++n;
		}
	}

	namespace ByRef
	{
		void next(int& n /*in-out*/)
		{
			++n;
		}
	}

	namespace ByConstRef
	{
		void print(const std::vector<int>& vec /*in*/, const std::string& desc = "vec")
		{
			std::cout << desc << " = [ ";
			for (const auto& item : vec)
				std::cout << item << " ";
			std::cout << "]\n";
		}
	}
}


int main()
{
	std::vector<int> data = { 1, 2, 3, 4, 5 };
	Hsbc::ByConstRef::print(data, "data");

	int x = 10;
	int y = 20;

	auto res = Hsbc::MyMath::Generic::square<int>(42.2);

	std::cout << "x * y = " << Hsbc::MyMath::multiply(x, y) << "\n";
	Hsbc::MyMath::print_line('#');
	std::cout << "square(x) = " << Hsbc::MyMath::square(x) << "\n";

	int result = Hsbc::ByValue::next(x);
	assert(x == 10);
	std::cout << "result: " << result << "\n";

	Hsbc::ByRef::next(x);
	assert(x == 11);
	std::cout << "x: " << result << "\n";

	system("PAUSE");
}