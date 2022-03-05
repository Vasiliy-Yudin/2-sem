#ifndef OURARRAY
#define OURARRAY
#include <iostream>
struct BadSize {};

template <typename T> class Arr {
private:
	T* storage;
	size_t size;

public:
	Arr();
	Arr(size_t);
	~Arr() {
		if (storage != nullptr) {
			delete[]storage;
		}
	}
	size_t getSize() const;
	T getElement(size_t);
	T removeElement(size_t);
	void addElement(T);
	void resize(size_t);
};


template <typename T>
Arr<T>::Arr() {
	size = 0;
	storage = nullptr;
	//m_valid = true;
}

template <typename T>
Arr<T>::Arr(size_t n) {
	if (n < 0)throw 1;
	size = n;
	storage = new T[n];
}

template <typename T>
size_t Arr<T>::getSize() const {
	return size;
}


template <typename T>
T Arr<T>:: getElement(size_t index) {
	if (index < size)
		return storage[index];
	return NULL;
}

template <typename T>
T Arr<T>::removeElement(size_t index) {
	if (index < size) {
		T el = *(storage + index);
		size_t j = 0;
		T *b = new T[size - 1];
		for (int i = 0; i < size; ++i)
			if (i != index) {
				b[j] = storage[i];
				++j;
			}//std::swap(a.storage[i], a.storage[i + 1]);
		delete[] storage;
		//std::cout << "b: " << b << std::endl;
		storage = b;
		//std::cout << "storage: " << storage << std::endl;
		--size;
		return el;
	}
}


template <typename T>
void Arr<T>::addElement(T el) {
	T *b = new T[size + 1];
	for (size_t i = 0; i < size; ++i) {
		b[i] = storage[i];
	}
	b[size] = el;
	delete[] storage;
	//std::cout << "del storage: " << storage << " = " << *storage << std::endl;
	++size;
	//std::cout << "b: " << b << std::endl;
	storage = b;
	//std::cout << "storage: " << storage<<" = "<<*storage << std::endl;
}

template <typename T>
void Arr<T>::resize(size_t new_size) {
	T *b = new T[new_size];
	for (size_t i = 0; i < new_size; ++i)b[i] = storage[i];
	delete[] storage;
	size = new_size;
	//std::cout << "b: " << b << std::endl;
	storage = b;
}
#endif