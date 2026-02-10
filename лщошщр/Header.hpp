#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <random>
class MyString
{
public:

	MyString() :MyString(16) {}

	MyString(int size)
		:size_(size), data_(new char[size_]) {}

	MyString(const char* str)
	{
		size_ = ::strlen(str);
		data_ = new char[size_];
		::memcpy(data_, str, size_);
	}

	~MyString()
	{
		if (data_)
		{
			delete[] data_;
		}
	}

	//перегрузка методом класса	
	//для обоюдного использования оператора нудна друж. функция
	friend MyString operator+(const MyString& rso, const MyString& lso)
	{
		MyString result;
		result.size_ = rso.size_ + lso.size_;


		int i = 0;
		for (; i < rso.size_; i++)
		{
			result.data_[i] = rso.data_[i];
		}

		for (int j = 0; j < lso.size_; j++)
		{
			result.data_[i + j] = lso.data_[j];
		}
		return result;
	}

	char& operator[](int i) 
	{
		return data_[i]; 
	}

	MyString& operator+=(const MyString& lso);

private:
	char* data_;
	int size_;
};

#endif // !HEADER_HPP

