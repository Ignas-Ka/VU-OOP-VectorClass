#pragma once

struct out_of_range
{

};

template<class T> class Vector
{
public:
	Vector();

	explicit Vector(int s);

	Vector(const Vector& arg);

	Vector<T>& operator=(const Vector<T>& arg);

	~Vector();

	class iterator;

	iterator begin();

	const iterator begin() const;

	iterator end();

	const iterator end() const;

	const iterator cbegin() const;

	const iterator cend() const;

	bool empty() const;

	size_t capacity() const;

	void reserve(int newmalloc);

	void resize(int newsize, T val = T());

	size_t size() const;

	size_t max_size() const;

	void shrink_to_fit();

	void clear();

	void push_back(const T& d);

	void pop_back();

	T& at(int n);

	const T& at(int n) const;

	T& operator[](int i);

	const T& operator[](int i) const;

	T& front();

	const T& front() const;

	T& back();

	const T& back() const;

	T* data();

	const T* data() const;

private:
	size_t	_size;		
	T* _elements;	
	size_t	_space;		
						
};



template<class T> class Vector<T>::iterator
{
public:
	iterator(T* p)
		:_curr(p)
	{}

	iterator& operator++()
	{
		_curr++;
		return *this;
	}

	iterator& operator--()
	{
		_curr--;
		return *this;
	}

	T& operator*()
	{
		return *_curr;
	}

	bool operator==(const iterator& b) const
	{
		return *_curr == *b._curr;
	}

	bool operator!=(const iterator& b) const
	{
		return *_curr != *b._curr;
	}

private:
	T* _curr;
};

template<class T>
Vector<T>::Vector()
	:_size(0), _elements(0), _space(0)
{}

template<class T>
inline Vector<T>::Vector(int s)
	: 
	_size(s), 
	_elements(new T[s]), 
	_space(s)
{
	for (int index = 0; index < _size; ++index)
		_elements[index] = T();
}

template<class T>
inline Vector<T>::Vector(const Vector& arg)
	:_size(arg._size), _elements(new T[arg._size])
{
	for (int index = 0; index < arg._size; ++index)
		_elements[index] = arg._elements[index];
}

template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if (this == &a) return *this;	

	if (a._size <= _space)
	{
		for (int index = 0; index < a._size; ++index)
		{
			_elements[index] = a._elements[index];
			_size = a._size;
			return *this;
		}
	}

	T* p = new T[a._size];

	for (int index = 0; index < a._size; ++index)
		p[index] = a._elements[index];

	delete[] _elements;
	_size = a._size;
	_space = a._size;
	_elements = p;
	return *this;
}

template<class T>
Vector<T>::~Vector()
{
	delete[] _elements;
}

template<class T>
inline typename Vector<T>::iterator Vector<T>::begin()
{
	return Vector<T>::iterator(&_elements[0]);
}

template<class T>
inline typename const Vector<T>::iterator Vector<T>::begin() const
{
	return Vector<T>::iterator(&_elements[0]);
}

template<class T>
inline typename Vector<T>::iterator Vector<T>::end()
{
	return Vector<T>::iterator(&_elements[_size]);
}

template<class T>
inline typename const Vector<T>::iterator Vector<T>::end() const
{
	return Vector<T>::iterator(&_elements[_size]);
}

template<class T>
inline typename const Vector<T>::iterator Vector<T>::cbegin() const
{
	return Vector<T>::iterator(&_elements[0]);
}

template<class T>
inline typename const Vector<T>::iterator Vector<T>::cend() const
{
	return Vector<T>::iterator(&_elements[_size]);
}

template<class T>
inline bool Vector<T>::empty() const
{
	return (_size == 0);
}

template<class T>
inline size_t Vector<T>::capacity() const
{
	return _space;
}

template<class T>
inline void Vector<T>::reserve(int newalloc)
{
	if (newalloc <= _space) return;

	T* p = new T[newalloc];

	for (int i = 0; i < _size; ++i)
		p[i] = _elements[i];

	delete[] _elements;

	_elements = p;

	_space = newalloc;
}

template<class T>
inline void Vector<T>::resize(int newsize, T val)
{
	reserve(newsize);

	for (int index = _size; index < newsize; ++index)
		_elements[index] = T();

	_size = newsize;
}

template<class T>
inline size_t Vector<T>::size() const
{
	return _size;
}


template<class T>
inline void Vector<T>::push_back(const T& d)
{
	if (_space == 0)
		reserve(8);
	else if (_size == _space)
		reserve(2 * _space);

	_elements[_size] = d;

	++_size;
}


template<class T>
inline T& Vector<T>::at(int n)
{
	if (n < 0 || _size <= n) throw out_of_range();
	return _elements[n];
}

template<class T>
inline const T& Vector<T>::at(int n) const
{
	if (n < 0 || _size <= n) throw out_of_range();
	return _elements[n];
}

template<class T>
inline T& Vector<T>::operator[](int i)
{
	return _elements[i];
}

template<class T>
inline const T& Vector<T>::operator[](int i) const
{
	return _elements[i];
}

template<class T>
inline T& Vector<T>::front()
{
	return _elements[0];
}

template<class T>
inline const T& Vector<T>::front() const
{
	return _elements[0];
}

template<class T>
inline T& Vector<T>::back()
{
	return _elements[_size - 1];
}

template<class T>
inline const T& Vector<T>::back() const
{
	return _elements[_size - 1];
}

template<class T>
inline T* Vector<T>::data()
{
	return _elements;
}

template<class T>
inline const T* Vector<T>::data() const
{
	return _elements;
}
