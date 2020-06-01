#ifndef MYVECTOR_H
#define MYVECTOR_H
#pragma once
template <class T>
class myVector
{
	T *data = NULL;
	int size;
public:
	myVector(int = 1);
	myVector(myVector&);
	myVector operator=(const myVector&);
	bool operator==(const myVector&);
	int Size() const;
	T& operator [](int);
	bool operator==(int);
	void push_back(T);
	void clear();
	void create(const int &);
	void erase(const int &);
	void insert(const int &, T);
	~myVector<T>(void);
};

#endif MYVECTOR_H

template <class  T>
myVector<T>::myVector(const int a)
{
	create(a);
}

template <class  T>
myVector<T>::~myVector()
{
	delete[] data;
}

template <class  T>
int myVector<T>::Size() const
{
	return size;
}

template <class  T>
T& myVector<T>::operator[](int i)
{
	return data[i];
}

template<class T>
bool myVector<T>::operator==(int)
{
	return false;
}

template <class T>
myVector<T> myVector<T>::operator=(const myVector &a)
{
	if (size < a.size) {
		delete[] data;
		data = new T[a.size];
	}
	size = a.size;
	for (int i = 0; i < a.size; i++) {
		this->data[i] = a.data[i];
	}
	return *this;
}

template <class T>
bool myVector<T>::operator==(const myVector &v)
{
	if (this->size == v.size)
	{
		for (int i = 0; i<this->size; i++)
		{
			if (this->data[i] != v.data[i])
				return false;
		}
		return true;
	}
	else {
		return  false;
	}
}

template <class T>
myVector<T>::myVector(myVector &a) {
	this->size = a.size;
	data = new T[size];
	for (int i = 0; i != a.size; ++i) {
		this->data[i] = a.data[i];
	}
}

template <class T>
void myVector<T>::push_back(T val) {
	T *newdata = new T[++this->size];
	for (int i = 0; i < this->size; i++){
		if (i != this->size - 1){
			newdata[i] = this->data[i];
		}
		else{
			newdata[i] = val;
			break;
		}
	}
	delete[] this->data;
	this->data = newdata;
}

template <class T>
void myVector<T>::insert(const int &n, T val) {
	int oldSize = this->size;
	this->size = (this->size >= n) ? (++this->size) : (this->size + (n - this->size));
	T *newdata = new T[this->size];
	int arrIndex = 0;
	for (int i2 = 0; i2 < this->size; i2++){
		if (i2 == n){
			newdata[i2] = val;
			continue;
		}
		if (arrIndex != oldSize){
			newdata[i2] = this->data[arrIndex++];
		}
	}
	delete[] this->data;
	this->data = newdata;
}

template <class  T>
void myVector<T>::erase(const int &i){
	T *newdata = new T[--this->size];
	T resItem;
	int resIndex = 0;
	for (int i2 = 0; i2 < this->size + 1; i2++){
		T item = this->data[i2];
		if (i == i2){
			resItem = item;
			continue;
		}
		newdata[resIndex++] = this->data[i2];
	}
	delete[] this->data;
	this->data = newdata;
}

template <class  T>
void myVector<T>::clear()
{
	delete[] this->data;
	this->size = 0;
	this->data = new T[1];
}

template <class  T>
void myVector<T>::create(const int &i) {
	if (this->data!=NULL)
		delete[] data;
	size = 0;
	data = new T[i];
}


