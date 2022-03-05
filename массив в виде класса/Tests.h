#pragma once
#include <iostream>
#include "Arr.h"

template <typename T>
void TestGet() {
	Arr<int> a(0);
	for (int i = 0; i < 9; ++i)a.addElement(rand() % 20 + 1);
	std::cout << "initial array: " << std::endl;
	print(a);
	for (size_t i = 0; i < a.getSize(); ++i)
		if (i % 2 == 0)std::cout << i << " element: " << a.getElement(i) << std::endl;
}

template <typename T>
void TestRemove() {
	Arr<int> a(0);
	for (int i = 0; i < 9; ++i)a.addElement(rand() % 20 + 1);
	std::cout << "initial array: " << std::endl;
	print(a);
	std::cout << "Delete 2 element: " << a.removeElement(2) << std::endl;
	print(a);
	std::cout << "Delete 4 element: " << a.removeElement(4) << std::endl;
	print(a);
}

template <typename T>
void TestAdd() {
	Arr<int> a(0);
	for (int i = 0; i < 9; ++i)a.addElement(rand() % 20 + 1);
	std::cout << "initial array: " << std::endl;
	print(a);
	a.addElement(10);
	std::cout << "Add 10: ";
	print(a);
	a.addElement(22);
	std::cout << "Add 22: ";
	print(a);
	a.addElement(1);
	std::cout << "Add 1: ";
	print(a);
}

template <typename T>
void TestResize() {
	Arr<int> a(0);
	for (int i = 0; i < 9; ++i)a.addElement(rand() % 20 + 1);
	std::cout << "initial array: " << std::endl;
	print(a);
	std::cout << "with initial size: " << a.getSize() << std::endl;
	a.resize(6);
	std::cout << "Resize to 6: ";
	print(a);
	a.resize(4);
	std::cout << "Resize to 4: ";
	print(a);
	a.resize(3);
	std::cout << "Resize to 3: ";
	print(a);
}