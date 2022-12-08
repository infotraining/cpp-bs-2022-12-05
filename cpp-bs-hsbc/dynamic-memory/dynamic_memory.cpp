#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <memory>
#include <cassert>
#include <map>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

using namespace std;

struct Gadget
{
	string name;	

	Gadget(const string& n = "not-set") // constructor
		: name(n)
	{
		cout << "Gadget(" << name << ": @" << this << ")\n";
	}

	~Gadget() // destructor
	{
		cout << "~Gadget(" << name << ": @" << this << ")\n";
	}

	void use()
	{
		cout << "Using " << name << ": @" << this << "\n";
	}
};

namespace Explain
{
	template <typename T>
	class Vector
	{
		T* array_;
		size_t size_;
	public:
		Vector(size_t size, T value = T{})
			: array_{ new T[size] }, size_{ size }
		{
			std::fill_n(array_, size_, value);
		}

		Vector(const Vector& source) // copy constructor
			: array_{new T[source.size()]}, size_{source.size()}
		{
			std::copy(source.array_, source.array_ + size_, array_);
		}

		Vector& operator=(const Vector& source) // copy ossignment operator
		{
			if (this != &source) // avoiding self-assignment
			{
				delete[] array_; // clean-up old items

				// copy
				array_ = new T[source.size()];
				size_ = source.size();
				std::copy(source.array_, source.array_ + size_, array_);
			}
			
			return *this;			
		}

		~Vector()
		{
			delete[] array_;
		}

		T& operator[](size_t index) // read-write
		{
			return array_[index];
		}

		const T& operator[](size_t index) const // read-only
		{
			return array_[index];
		}

		T& at(size_t index) // read-write
		{
			if (index >= size_)
				throw std::out_of_range("Index out of range");
			return array_[index];
		}

		const T& at(size_t index) const // read-only
		{
			if (index >= size_)
				throw std::out_of_range("Index out of range");
			return array_[index];
		}

		size_t size() const
		{
			return size_;
		}
	};

	struct DataSet
	{
		Vector<int> row1{ 10 };
		Vector<int> row2{ 10 };
	};
}



void vector_and_copy_constructors()
{
	using namespace Explain;

	int size{};

	std::cout << "Podaj rozmiar: ";
	std::cin >> size;

	Vector<int> vec(size, -1);

	vec[5] = 7;

	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";

	{
		Vector<Gadget> gadgets(10);
		gadgets[6] = Gadget{ "ipad" };
		gadgets[6].use();
	}

	Gadget g1{ "g1" };
	Gadget g2 = g1;
	g1 = Gadget{ "g2" };

	std:cout << "-------------------\n";

	Vector<Gadget> gs1(4, Gadget{ "four" });

	Vector<Gadget> gs2 = gs1; // call to copy constructor

	gs2[1].name = "bad boy";

	gs1[1].use();
	
	gs1 = Vector<Gadget>(2); // copy assignment

	gs1 = gs1;

	const Vector<int> ds(10, -1);
	std::cout << ds[0] << "\n";

}

//int main()
//{
//	std::cout << "start\n";
//	{
//		Gadget g1_on_stack("ipad");
//		g1_on_stack.use();
//	}
//	std::cout << "----\n";
//
//	//////////////////////////
//	// old (deprecated) style
//	Gadget* ptr_g2_on_heap = nullptr;
//	int size = 100;
//	Gadget* gadget_dynamic_array = new Gadget[size]; // new for arrays
//	gadget_dynamic_array[2].use();	
//	
//	for(int i = 0; i < 10; ++i) // large memory leak
//	{
//		ptr_g2_on_heap = new Gadget("smartphone"); // object created on heap - new for single object
//	}
//
//	if (ptr_g2_on_heap)
//	{
//		ptr_g2_on_heap->use();
//		(*ptr_g2_on_heap).use();
//	}
//
//	std::vector<int> vec = { 1, 2, 3, 4 };
//
//	vec.at(10) = 10; // throws std::out_of_range
//
//	delete ptr_g2_on_heap; // object destroyed & memory freed
//	delete[] gadget_dynamic_array;
//
//	ptr_g2_on_heap->use(); // UB
//
//	_CrtDumpMemoryLeaks();
//}

template <typename T>
class ScopedPtr
{
	T* ptr_;
public:
	ScopedPtr(T* ptr) : ptr_{ptr}
	{}

	ScopedPtr(const ScopedPtr&) = delete;
	ScopedPtr& operator=(const ScopedPtr&) = delete;

	~ScopedPtr()
	{
		delete ptr_;
	}

	T* operator->() const
	{
		return ptr_;
	}

	T& operator*() const
	{
		return *ptr_;
	}
};

std::unique_ptr<Gadget> create_gadget()
{
	static int id = 0;

	return std::unique_ptr<Gadget>(new Gadget{ "G#" + std::to_string(++id) });
}

void use_and_destroy(std::unique_ptr<Gadget> uptr)
{
	if (uptr)
		uptr->use();
}

namespace LegacyCode
{
	std::vector<int>* load_big_data()
	{
		std::vector<int>* ptr_large_vec = new std::vector<int>(1'000'000);
		return ptr_large_vec;
	}

	void free_big_data(std::vector<int>* ptr)
	{
		delete ptr;
	}
}

namespace ModernCpp
{
	std::vector<int> load_big_data()
	{
		std::vector<int> large_vec(1'000'000);
		return large_vec;
	}	
}

void using_legacy_code()
{
	std::vector<int>* ptr_large_vec = LegacyCode::load_big_data();
	//... using ptr_large_vec
	
	LegacyCode::free_big_data(ptr_large_vec);
}

void using_modern_cpp()
{
	std::vector<int> vec = ModernCpp::load_big_data();
}

int main()
{
	{  // legacy style	
		Gadget* ptr_g1{};
		try
		{
			ptr_g1 = new Gadget("ipad");
			ptr_g1->use();

			Explain::Vector<int> vec(10);
			vec.at(1) = 666;

			// ...
			delete ptr_g1;
		}
		catch (...)
		{
			delete ptr_g1;
			throw;
		}
	}

	{ // ScopedPtr
		ScopedPtr<Gadget> ptr_g1{ new Gadget("ipad") };
		ptr_g1->use();
		(*ptr_g1).use();

		//ScopedPtr<Gadget> ptr_g2 = ptr_g1;

		Explain::Vector<int> vec(10);

		std::ofstream file_out("data.txt");
		
		if (!file_out)
			std::terminate();
		
		file_out << "Text: " << 24 << "\n";

		vec.at(1) = 666;
	}

	{
		std::unique_ptr<Gadget> uptr1(new Gadget{ "g controlled by unique_ptr" });
		uptr1->use();

		std::unique_ptr<Gadget> uptr2 = std::move(uptr1);
		assert(uptr1.get() == nullptr);
		uptr2->use();

		std::unique_ptr<Gadget> uptr3 = create_gadget();
		uptr3->use();

		use_and_destroy(std::move(uptr3));
		use_and_destroy(create_gadget());

		{
			std::vector<std::unique_ptr<Gadget>> vec_ptrs;
			vec_ptrs.push_back(std::unique_ptr<Gadget>(new Gadget("ipad1")));
			vec_ptrs.push_back(std::make_unique<Gadget>("ipad2"));
			vec_ptrs.push_back(std::make_unique<Gadget>("ipad3"));
		}
	}

	{
		std::map<std::string, std::shared_ptr<Gadget>> dict_g;

		{
			std::shared_ptr<Gadget> sg1 = std::make_shared<Gadget>("ipad shared");
			auto sg2 = sg1;
			assert(sg1.use_count() == 2);
			dict_g["the_best"] = sg1;
			assert(sg1.use_count() == 3);
		}

		dict_g["the_best"]->use();
	}
}
