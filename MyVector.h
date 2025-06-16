#ifndef MyVector_H
#define MyVector_H

#include <iostream>
#include "raylib.h"
using namespace std;

template <typename T>
class MyVector {
private:
	T* data;
	int len;
	int cap;

	void double_capacity();

public:
	MyVector();
	MyVector(const MyVector& other);
	~MyVector();

	// Operators
	MyVector& operator=(const MyVector& other);
	T& operator[](int index);
	const T& operator[](int index) const;
	bool operator==(const MyVector& other) const;
	bool operator!=(const MyVector& other) const;
	MyVector operator+(const MyVector& other) const;
	MyVector& operator+=(const MyVector& other);

	// Modifiers
	void push(T value);
	void pop();
	void insert_at(int index, int value);
	void delete_at(int index);
	void reserve(int new_capacity);
	void clear();
	void swap(MyVector& other);
	void shrink_to_fit();
	void reverse();

	// Accessors
	bool empty() const; // Checks if array is empty
	int size() const;   // Returns current size

	T& at(int index); // Bounds-checked element access
	const T& at(int index) const;

	T& front(); // Returns first element
	const T& front() const;

	T& back(); // Returns last element
	const T& back() const;

	int find(T value) const; // Return index of first instance, or -1 if non-existent
};

#endif // MyVector_H