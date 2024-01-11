#pragma once
#include "my_string.h"

class BinaryNumber : public MyString
{
public:
	BinaryNumber(const char* bin);
	int ToDecimal() const;
	char* c_str();
};

