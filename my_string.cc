#include "my_string.h"
#include <cstring>
#include <iostream>

int MyString::string_cnt = 0;

// Конструктор принимающий максимальную длину строки
MyString::MyString(int init_len) {
	max_len_ = init_len;
	str_ = new char[max_len_];
	str_len_ = 0;
	string_cnt += 1;
}

MyString::MyString() : MyString(50) {}
MyString::MyString(MyString& other) : MyString(other.max_len_) {}

// Деструктор, удаляющий строку из памяти
MyString::~MyString() {
	delete[] str_;
	string_cnt -= 1;
}

// Установка новой строки
void MyString::SetString(const char* new_str) {
	int new_len = strlen(new_str);
	if (new_len > max_len_) {
		max_len_ = 2 * new_len;
		char* new_sarr = new char[max_len_];
		delete[] str_;
		str_ = new_sarr;
	}

	strcpy(str_, new_str);
	str_len_ = new_len;
}

// Проверка на содержание субстроки sub в строке
bool MyString::Contains(const char* sub) const {
	return strstr(str_, sub) != nullptr;
}

// Вернуть длину строки
int MyString::GetLength() const {
	return str_len_;
}

// Вернуть максимальную длину строки
int MyString::GetMaxLength() const {
	return max_len_;
}

void MyString::SetLength(int new_len) {
	str_len_ = new_len;
}

void MyString::SetMaxLength(int new_max_len) {
	max_len_ = new_max_len;
}

// Строковое представление класса
char* MyString::c_str() {
	char* str = new char[max_len_ + 128];
	sprintf(str, "Строка: \"%s\"; Длина: %d; Максимальная длина: %d;\n", str_, str_len_, max_len_);
	return str;
}

const char* MyString::GetString() const {
	return str_;
}