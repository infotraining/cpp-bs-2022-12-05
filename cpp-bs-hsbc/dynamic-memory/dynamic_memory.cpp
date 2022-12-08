#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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

int main()
{
	{
		Gadget g1_on_stack("ipad");
		g1_on_stack.use();
	}

	{
		Gadget* ptr_g = new Gadget{ "ipod" };
	} 

	system("PAUSE");
}