#include "Vector.h"
#include <exception>
Vector::Vector()
	: size(0),
	capacity(5),
	array(new int[capacity])
{
}

Vector::Vector(const Vector& rhs)
	: size(rhs.size),
	capacity(rhs.capacity + 5),
	array(new int[capacity])
{
	for (int i = 0; i < rhs.Size(); ++i) {
		array[i] = rhs.array[i];
	}
}

Vector::Vector(int elements, int value)
	: size(elements),
	capacity(elements + 5),
	array(new int[capacity])
{
	for (int i = 0; i < size; ++i) {
		array[i] = value;
	}
}

Vector::~Vector()
{
	delete[] array;
}

void Vector::push_back(int value)
{
	if (size < capacity)
	{
		array[size] = value;
		++size;
	}
	else 
	{
		capacity *= 2;
		int* newarray = new int[capacity];
		for (int i = 0; i < size; ++i)
		{
			newarray[i] = array[i];
		}
		newarray[size] = value;
		++size;
		delete[] array;
		array = newarray;
	}

}

void Vector::pop_back()
{
	if (size == 0)
	{
		throw std::exception("Pop back on empty vector!");
	}
	--size;
}

bool Vector::Empty() const
{
	return size == 0;
}


int Vector::Size() const
{
	return size;
}

int Vector::Capacity() const
{
	return capacity;
}

bool Vector::operator==(const Vector& rhs) const
{
	if (Size() != rhs.Size())
	{
		return false;
	}

	for (int i = 0; i < Size(); ++i) {
		if (array[i] != rhs.array[i]) {
			return false;
		}
	}

	return true;
}

bool Vector::operator!=(const Vector& rhs) const
{
	return !(*this == rhs);
}

Vector& Vector::operator=(const Vector& rhs)
{
	if (rhs.size > size)
	{
		delete[] array;
		capacity = rhs.size + 5;
		array = new int[capacity];
	}
	for (int i = 0; i < rhs.Size(); ++i)
	{
		array[i] = rhs.array[i];
	}

	size = rhs.size;

	return *this;
}

int& Vector::operator[](int index)
{
	return array[index];
}

int& Vector::at(int index)
{
	if ((index < 0) || (index >= size))
	{
		throw std::exception("Index out of range!");
	}
	return array[index];
}

int& Vector::front()
{
	return array[0];
}

int& Vector::back()
{
	return array[size-1];
}

void Vector::insert(int index, int value)
{
	if ((index < 0) || (index >= size))
	{
		throw std::exception("Insert - index out of range!");
	}

	if (size != capacity)
	{
		for (int i = size - 1; i >= index; --i)
		{
			array[i + 1] = array[i];
		}
		array[index] = value;
		++size;
	}
	else
	{
		capacity *= 2;
		int* newarray = new int[capacity];
		for (int i = 0; i < size; ++i)
		{
			newarray[i] = array[i];
		}
		delete[] array;
		array = newarray;
		insert(index, value);
	}
}

void Vector::erase(int index)
{
	if ((index < 0) || (index >= size))
	{
		throw std::exception("Erase - index out of range!");
	}

	for (int i = index; i < size - 1; ++i)
	{
		array[i] = array[i + 1];
	}
	--size;
}

void Vector::clear()
{
	size = 0;
}


