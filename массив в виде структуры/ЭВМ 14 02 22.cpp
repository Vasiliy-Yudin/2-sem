#include <iostream>
#include <ctime>
template <typename T>
struct Arr {
	T* storage;
	size_t size;
};

template <typename T>
void print(Arr<T> a) {
	for (size_t i = 0; i < a.size; ++i)std::cout << a.storage[i] << " ";
	std::cout << std::endl;
}

template <typename T>
T* getElement(Arr<T> &a,size_t index) {
	if (index < a.size)
		return &(a.storage[index]);
	return NULL;
}

template <typename T>
T removeElement(Arr<T> &a,size_t index) {
	if (index < a.size) {
		T el = *(a.storage + index);
		size_t j = 0;
		T *b = new T[a.size-1];
		for (int i =0/*index*/; i < a.size;++i) 
			if (i != index) {
				b[j] = a.storage[i];
				++j;
			}//std::swap(a.storage[i], a.storage[i + 1]);
		//delete[] a.storage;
		a.storage = b;
		--a.size;
		return el;
	}
}

template <typename T>
void addElement(Arr<T> &a, T el) {
	T *b = new T[a.size + 1];
	for (size_t i = 0; i < a.size; ++i)b[i] = a.storage[i];
	//delete[] a.storage;
	b[a.size]=el;
	++a.size;
	a.storage = b;
}

template <typename T>
void resize(Arr<T> &a,size_t new_size) {
	T *b = new T[new_size];
	for (size_t i = 0; i < new_size; ++i)b[i] = a.storage[i];
	//delete[] a.storage;
	a.size = new_size;
	a.storage = b;
}

template <typename T>
void TestGet(Arr<T> a) {
	for (size_t i = 0; i < a.size; ++i)
		if (i % 2 == 0)std::cout <<i<<" element: "<< *getElement(a,i)<<std::endl;
}

template <typename T>
void TestRemove(Arr<T> a) {
	std::cout<<"Delete 2 element: "<<removeElement(a, 2)<<std::endl;
	print(a);
	std::cout << "Delete 4 element: " << removeElement(a, 4) << std::endl;
	print(a);
}

template <typename T>
void TestAdd(Arr<T> a) {
	addElement(a, 10);
	std::cout << "Add 10: ";
	print(a);
	addElement(a, 22);
	std::cout << "Add 22: ";
	print(a);
}

template <typename T>
void TestResize(Arr<T> a) {
	std::cout << "Initial size: " << a.size<<std::endl;
	resize(a, 4);
	std::cout << "Resize to 4: ";
	print(a);
	resize(a, 6);
	std::cout << "Resize to 6: ";
	print(a);
	resize(a, 3);
	std::cout << "Resize to 3: ";
	print(a);
}

int main()
{
	srand(time(0));
	Arr<int> a;
	a.size = 10;
	a.storage = new int[a.size];
	for (int i = 0; i < a.size; ++i)a.storage[i] = rand()%20+1;
	std::cout << "initial version: "<<std::endl;
	print(a);
	std::cout<< "\nTest getElement:" << std::endl;
	TestGet(a);
	std::cout << "\nTest removeElement:" << std::endl;
	TestRemove(a);
	std::cout << "\nTest addElement:" << std::endl;
	TestAdd(a);
	std::cout << "\nTest resize:" << std::endl;
	TestResize(a);
}

