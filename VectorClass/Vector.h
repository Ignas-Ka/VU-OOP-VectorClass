#pragma once
class Vector
{
public:
	Vector();
	Vector(const Vector& rhs);
	Vector(int elements, int value = 0);;
	~Vector();

	void push_back(int value);
	void pop_back();

	bool Empty() const;
	int Size() const;
	int Capacity() const;

	bool operator==(const Vector& rhs) const;
	bool operator!=(const Vector& rhs) const;

	Vector& operator=(const Vector& rhs);

	int& operator[](int index);
	int& at(int index);
	int& front();
	int& back();

	void insert(int index, int value);
	void erase(int index);
	void clear();


private:
	int size;
	int capacity;
	int* array;
};