#pragma once
template <class T>
class myVector
{
	T *data;
	int size;
	int cap;
public:
	myVector(int = 1);
	myVector(myVector&);
	myVector operator=(const myVector&);
	bool operator==(const myVector&);
	int capacity() const;
	int Size() const;
	T& operator [](int);
	bool operator==(int);
	void push_back(T);
	void clear();
	void create(const int &);
	void erase(const int &);
	void resize(const int &);
	void insert(const int &, T);
	~myVector<T>(void);
};

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
	size = a.size;
	for (int i = 0; i != a.size; ++i) {
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
	for (int i = 0; i != a.size; ++i) {
		this->data[i] = a.data[i];
	}
}

template <class T>
void myVector<T>::push_back(T val) {
	T* newdata;
	if (size>cap) {
		cap = cap * 2;
		newdata = new T[cap];
		for (int i = 0; i<size; i++)
			newdata[i] = data[i];
		delete[] data;
		data = newdata;
	}
	data[size] = val;
	size++;
}

template <class  T>
int myVector<T>::capacity() const
{
	return cap;
}

template <class  T>
void myVector<T>::erase(const int &i){
	T* newdata = new T[cap];
	bool f = false;
	for (int j = 0; j<this->size; j++)
	{
		if (j == i)
			f = true;
		if (f)
			newdata[j - 1] = this->data[j];
		else 
			newdata[j] = this->data[j];
	}
	this->size -= 1;
	delete[] this->data;
	this->data = newdata;
}

template <class  T>
void myVector<T>::resize(const int &n)
{
	T* newdata = new T[n];
	this->cap = n;
	this->size = n>this->size ? this->size : n;
	for (int i = 0; i<this->size; i++)
	{
		newdata[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newdata;
}


template <class  T>
void myVector<T>::clear()
{
	delete[] this->data;
	this->size = 0;
	this->cap = 1;
	this->data = new T[1];
}

template <class  T>
void myVector<T>::create(const int &i) {
	if (this->data)
		delete[] data;
	size = 0;
	cap = i;
	data = new T[i];
}

template <class T>
void myVector<T>::insert(const int &n, T data) {
	if (size + 1 > cap)cap *= 2;
	T* newdata = new T[cap];
	bool f = false;
	for (int i = 0; i < size ; i--) {
		if (i == n)f = true;
		if (f)
			newdata[i + 1] = this->data[i];
		else
			newdata[i] = this->data[i];
	}
	newdata[n] = data;
	this->data = newdata;
	size++;
}

