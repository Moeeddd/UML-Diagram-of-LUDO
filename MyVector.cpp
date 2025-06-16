#include "MyVector.h";

template <typename T>
void MyVector<T>::double_capacity() {
	this->cap = this->cap * 2;
	T* new_data = new T[cap];
	for (int i = 0; i < len; ++i) {
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
}

template <typename T>
MyVector<T>::MyVector() : data(nullptr), len(1), cap(1) {}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) {
	this->len = other.len;
	this->cap = other.cap;
	for (int i = 0; i < this->len; i++) {
		this->data[i] = other.data[i];
	}
}

template <typename T>
MyVector<T>::~MyVector() {
	delete[] data;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this != &other) {
		delete[] data;
		this->len = other.len;
		this->cap = other.cap;
		data = new T[cap];
		for (int i = 0; i < this->len; i++) {
			this->data[i] = other.data[i];
		}
	}
	return *this;
}


template <typename T>
T& MyVector<T>::operator[](int index) {
	if (index < 0 || index >= len) {
		cout << "Index out of range\n";
	}
	return data[index];
}

template <typename T>
const T& MyVector<T>::operator[](int index) const {
	if (index < 0 || index >= len) {
		cout << "Index out of range\n";
	}
	return data[index];
}

template <typename T>
bool MyVector<T>::operator==(const MyVector& other) const {
	if (this->len != other.len) {
		return false;
	}
	for (int i = 0; i < len; ++i) {
		if (this->data[i] != other.data[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool MyVector<T>::operator!=(const MyVector& other) const {
	if (*this == other) {
		return true;
	}
	return false;
}

template <typename T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& other) const {
	MyVector result;
	result.reserve(len + other.len);
	for (int i = 0; i < len; ++i) {
		result.push(data[i]);
	}
	for (int i = 0; i < other.len; ++i) {
		result.push(other.data[i]);
	}
	return result;
}

template <typename T>
MyVector<T>& MyVector<T>::operator+=(const MyVector<T>& other) {
	for (int i = 0; i < other.len; ++i) {
		this->push(other.data[i]);
	}
	return *this;
}

template <typename T>
void MyVector<T>::push(T value) {
	if (this->len == this->cap) {
		this->double_capacity();
	}
	data[this->len] = value;
	this->len++;
}

template <typename T>
void MyVector<T>::pop() {
	if (this->len > 0) {
		data[this->len] = 0;
		this->len--;
	}
}

template <typename T>
void MyVector<T>::insert_at(int index, int value) {
	if (len == cap) double_capacity();
	for (int i = len; i > index; --i) {
		data[i] = data[i - 1];
	}
	data[index] = value;
	len++;
}

template <typename T>
void MyVector<T>::delete_at(int index) {
	if (index >= 0 || index < len) {
		for (int i = index; i < len - 1; ++i) {
			data[i] = data[i + 1];
		}
		len--;
	}
	else {
		cout << "Index out of scope\n";
	}
}

template <typename T>
void MyVector<T>::reserve(int new_capacity) {
	cap = new_capacity;
	int* new_data = new int[cap];
	for (int i = 0; i < len; ++i) {
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
}

template <typename T>
void MyVector<T>::clear() {
	this->len = 0;
}

template <typename T>
void MyVector<T>::swap(MyVector& other) {
	int* temp_data = this->data;
	int temp_len = this->len;
	int temp_cap = this->cap;

	this->data = other.data;
	this->len = other.len;
	this->cap = other.cap;

	other.data = temp_data;
	other.len = temp_len;
	other.cap = temp_cap;
}

template <typename T>
void MyVector<T>::shrink_to_fit() {
	cap = len;
	int* new_data = new int[cap];
	for (int i = 0; i < len; ++i) {
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
}

template <typename T>
void MyVector<T>::reverse() {
	for (int i = 0; i < len / 2; ++i) {
		int temp = data[i];
		data[i] = data[len - 1 - i];
		data[len - 1 - i] = temp;
	}
}

template <typename T>
bool MyVector<T>::empty() const {
	if (len == 0) {
		return true;
	}
	return false;
}

template <typename T>
int MyVector<T>::size() const {
	return this->len;
}

template <typename T>
T& MyVector<T>::at(int index) {
	if (index < 0 || index >= len) {
		cout << "Index out of range\n";
	}
	return data[index];
}

template <typename T>
const T& MyVector<T>::at(int index) const {
	if (index < 0 || index >= len) {
		cout << "Index out of range\n";
	}
	return data[index];
}

template <typename T>
T& MyVector<T>::front() {
	if (len == 0) {
		cout << "Array is empty\n";
	}
	return data[0];
}

template <typename T>
const T& MyVector<T>::front() const {
	if (len == 0) {
		cout << "Array is empty\n";
	}
	return data[0];
}

template <typename T>
T& MyVector<T>::back() {
	if (len == 0) {
		cout << "Array is empty\n";
	}
	return data[len - 1];
}

template <typename T>
const T& MyVector<T>::back() const {
	if (len == 0) {
		cout << "Array is empty\n";
	}
	return data[len - 1];
}

template <typename T>
int MyVector<T>::find(T value) const {
	for (int i = 0; i < len; ++i) {
		if (data[i] == value) {
			return i;
		}
	}
	return -1;
}