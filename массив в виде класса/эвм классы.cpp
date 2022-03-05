#include <iostream>
#include <ctime>
#include "Arr.h"
#include "Tests.h"
template <typename T>
void print(Arr<T> &a) {
	for (size_t i = 0; i < a.getSize(); ++i)std::cout << a.getElement(i) << " ";
	std::cout << std::endl;
}

int main()
{
	srand(time(0));
	try{
		std::cout << "\n-----------Test getElement-------------" << std::endl;
		TestGet<int>();
		std::cout << "\n-----------Test removeElement----------" << std::endl;
		TestRemove<int>();
		std::cout << "\n-----------Test addElement-------------" << std::endl;
		TestAdd<int>();
		std::cout << "\n-----------Test resize-----------------" << std::endl;
		TestResize<int>();
	}
	catch (int) {
		std::cout << "Error";
	}
	return 0;
}

