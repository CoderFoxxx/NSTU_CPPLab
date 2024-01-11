#include <iostream>
#include <sstream>
#include "binary_number.h"
#include "null_ptr.h"

BinaryNumber::BinaryNumber(const char* bin) : MyString(bin) {
	for (int i = 0; i < GetLength(); ++i) {
		if (bin[i] != '0' && bin[i] != '1') {
			std::stringstream sstr;
			sstr << "Invalid binary number. Digit at position " << i << " has value of " << bin[i] << ". Digits in the binary number must be either 0 or 1.";
			throw std::invalid_argument(sstr.str().c_str());
		}
	}
}

int BinaryNumber::ToDecimal() const {
	int decimal = 0;
	int power = 1;

	for (int i = GetLength() - 1; i >= 0; --i) {
		if (GetString()[i] == '1') {
			decimal += power;
		}

		power *= 2;
	}

	return decimal;
}

char* BinaryNumber::c_str() {
	char* result;
	std::stringstream ss;
	ss << "Двоичное число: " << GetString();
	result = new char[strlen(ss.str().c_str()) + 1];
	sprintf(result, "%s", ss.str().c_str());
	return result;
}