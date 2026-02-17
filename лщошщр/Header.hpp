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
		:size_(size), data_(new char[size_+1]) {}

	MyString(const char* str)
	{
		size_ = ::strlen(str);
		data_ = new char[size_+1];
		::memcpy(data_, str, size_);
	}

	MyString(const MyString& other)
	{
		size_ = other.size_;
		data_ = new char[size_ + 1] {};
		::memcpy(data_, other.data_, size_);
	}

	//правило трёх - если требуется деструктор, 
	//конструктор копирования или оператор присваивания копирования
	//для управления ресурсами, то нужно реализовать все три.
	

	//правило пяти - если в программе требуется перенос данных
	//через конструктор переноса либо присваивание переносом
	//то нужно реализовать все пять блоков
	//(3 из правила трёх + конструктор переноса + присваивания переносом)

	MyString(MyString&& other)
	{
		size_ = 0;
		data_ = nullptr;
		std::swap(size_, other.size_);
		std::swap(data_, other.data_);
	}

	MyString& operator=(MyString&& other)
	{
		std::swap(size_, other.size_);
		std::swap(data_, other.data_);
	}

	~MyString()
	{
		if (data_)
		{
			delete[] data_;
		}
	}


	int Size()const { return size_; }
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
		int j = 0;
		for (; j < lso.size_; j++)
		{
			result.data_[i + j] = lso.data_[j];
		}
		//result.data_[i + j] = '\0';
		return result;
	}

	char& operator[](int i) 
	{
		return data_[i]; 
	}

	const char& operator[](int i)const
	{
		return data_[i];
	}


	MyString& operator+=(const MyString& lso)
	{
		auto tmp = new char[size_ + lso.size_];
		::memcpy(tmp, data_, size_);
		::memcpy(tmp + size_, lso.data_, lso.size_);
		std::swap(tmp, data_);
		delete tmp;
		return *this;
	}

private:
	char* data_;
	int size_;
};

#endif // !HEADER_HPP

