#include <iostream>
#include <cstring>
#include <sstream>
#include "null_ptr.h"

#pragma once
class MyString
{
public:
	MyString(int init_len);
	MyString(const char* s);
	MyString();
	MyString(const MyString& other);
	virtual ~MyString();

	const char* GetString() const;
	int GetMaxLength() const;
	int GetLength() const;
	void SetString(const char* new_str);
	void SetMaxLength(int new_max_len);
	void SetLength(int new_len);
	MyString Concat(const char* str);
	MyString Replace(const char* what, const char* replacement);
	bool Contains(const char* sub) const;
	virtual char* c_str();

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	MyString operator+(const char* str);
	MyString operator-(const char* sub);
	char operator[](int idx);
	MyString& operator=(const char* str);
	MyString& operator=(const MyString& other);

	static int string_cnt;
private:
	char* str_;
	int max_len_;
	int str_len_;
	const int MAX_BUFFER_SIZE = pow(2, 31) - 1;

friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
friend std::istream& operator>>(std::istream& is, MyString& obj);
};