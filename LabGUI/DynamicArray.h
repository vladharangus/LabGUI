#pragma once
//#include "Statue.h"

template <typename T>


class DynamicArray
{
private:
	int size;
	int capacity = 5;
	T* itemlist;
public:
	DynamicArray(int capacity);
	DynamicArray();
	DynamicArray(const DynamicArray& vector);
	void SaveItem(T item);
	void SaveExistingItem(int position, T item);
	void DeleteItem(int position);
	int GetSize();
	T* GetItems();
	T& operator[](int position);
	DynamicArray& operator=(const DynamicArray& vector);
	~DynamicArray();
};

template <typename T>
DynamicArray<T>::DynamicArray(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->itemlist = new T[5];
}

template <typename T>
DynamicArray<T>::DynamicArray()
{
	this->size = 0;
	this->capacity = 5;
	this->itemlist = new T[5];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->itemlist = new T[this->capacity];
	for (int index = 0; index < this->size; index++)
		this->itemlist[index] = vector.itemlist[index];
}

template <typename T>
T& DynamicArray<T>::operator[](int position)
{
	if (position > this->size)
		return this->itemlist[0];
	return this->itemlist[position];
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray & vector)
{
	if (this == &vector)
		return *this;
	this->capacity = vector.capacity;
	this->size = vector.size;

	delete[] this->itemlist;
	this->itemlist = new T[this->capacity];
	for (int index = 0; index < this->size; index++)
			this->itemlist[index] = vector.itemlist[index];
	return *this;
}

template <typename T>
void DynamicArray<T>::SaveItem(T item)
{
	if (this->size >= this->capacity)
	{
		this->capacity *= 2;
		T* newlist = new T[this->capacity];
		for (int index = 0; index < this->size; index++)
			newlist[index] = this->itemlist[index];
		this->itemlist = newlist;
	}
	this->itemlist[this->size++] = item;
}

template <typename T>
void DynamicArray<T>::SaveExistingItem(int position, T item)
{
	this->itemlist[position] =item;
}

template <typename T>
int DynamicArray<T>::GetSize()
{
	return this->size;
}

template <typename T>
T * DynamicArray<T>::GetItems()
{
	return this->itemlist;
}

template <typename T>
void DynamicArray<T>::DeleteItem(int position)
{
	for (int index2 = position; index2 < this->size - 1; index2++)
		this->itemlist[index2] = this->itemlist[index2 + 1];
	this->size--;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->itemlist;
}