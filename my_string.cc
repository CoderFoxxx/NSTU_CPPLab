#include "my_string.h"

int MyString::string_cnt = 0;

// Конструктор принимающий максимальную длину строки
MyString::MyString(int init_len) {
	if (init_len >= 0) {
		max_len_ = init_len;
		str_ = new char[max_len_ + 1];
		str_len_ = 0;
		string_cnt += 1;
	}
	else throw std::invalid_argument("Initial length should be greater or equal to 0");
}

MyString::MyString(const char* s) : MyString((s == nullptr) ? 0 : strlen(s) + 1) {
	if (s != nullptr)
		SetString(s);
	else throw null_ptr(&s);
}

MyString::MyString() : MyString(128) {}
MyString::MyString(const MyString& other) : MyString(other.GetString()) {}

// Деструктор, удаляющий строку из памяти
MyString::~MyString() {
	delete[] str_;
	string_cnt -= 1;
}

// Установка новой строки
void MyString::SetString(const char* new_str) {
	if (new_str != nullptr) {
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
	else throw null_ptr(&new_str);
}

// Проверка на содержание субстроки sub в строке
bool MyString::Contains(const char* sub) const {
	if (sub != nullptr)
		return strstr(str_, sub) != nullptr;
	else throw null_ptr(&sub);
}

// Вернуть длину строки
int MyString::GetLength() const {
	return str_len_;
}

// Вернуть максимальную длину строки
int MyString::GetMaxLength() const {
	return max_len_;
}

// Установить новую длину строки
void MyString::SetLength(int new_len) {
	str_len_ = new_len;
}

// Установить новую макс. длину строки
void MyString::SetMaxLength(int new_max_len) {
	max_len_ = new_max_len;
}

MyString MyString::Concat(const char* str) {
	if (str != nullptr) {
		int len = strlen(str);
		MyString result(len);
		char* concatenated = new char[str_len_ + len + 1];
		sprintf(concatenated, "%s%s", str_, str);
		result.SetString(concatenated);
		return result;
	}
	else throw null_ptr(&str);
}

MyString MyString::Replace(const char* what, const char* replacement) {
	if (what != nullptr) {
		int what_len = strlen(what);
		if (replacement != nullptr) {
			int replacement_len = strlen(replacement);
			int cnt = 0;
			char* temp = str_;
			while ((temp = strstr(temp, what)) != nullptr) {
				cnt++;
				temp += what_len;
			}
			int new_len = str_len_ + (replacement_len - what_len) * cnt;
			MyString result(new_len);
			char* dest = result.str_;
			const char* src = str_;
			while (cnt > 0) {
				temp = (char*)strstr(src, what);
				if (temp != nullptr) {
					int num_chars = temp - src;
					strncpy(dest, src, num_chars);
					dest += num_chars;
					src = temp + what_len;
					strncpy(dest, replacement, replacement_len);
					dest += replacement_len;
					cnt--;
				}
				else break;
			}

			strcpy(dest, src);
			result.SetLength(new_len);
			if (result.GetLength() > GetMaxLength()) {
				result.SetMaxLength(max_len_);
			}
			return result;
		}
		else throw null_ptr(&replacement);
	}
	else throw null_ptr(&what);
}

// Строковое представление класса
char* MyString::c_str() {
	char* str = new char[max_len_ + 128];
	sprintf(str, "Строка: \"%s\"; Длина: %d; Максимальная длина: %d;\n", str_, str_len_, max_len_);
	return str;
}

// Строка
const char* MyString::GetString() const {
	return str_;
}

MyString MyString::operator+(const char* str) {
	MyString result(max_len_ + strlen(str));
	result.SetString(str_);
	result = result.Concat(str);
	return result;
}

MyString MyString::operator-(const char* sub) {
	MyString result(max_len_);
	result.SetString(str_);
	result = result.Replace(sub, "\0");
	return result;
}

char MyString::operator[](int idx) {
	if (idx >= 0 && idx < str_len_) return str_[idx];
	std::stringstream str;
	str << "index " << idx << " out of range: " << str_len_ - 1;
	throw new std::out_of_range(str.str().c_str());
}

MyString& MyString::operator=(const char* str) {
	SetString(str);
	return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
	MyString result(lhs);
	return result.Concat(rhs.GetString());
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		SetString(other.str_);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& obj) {
	os << obj.str_;
	return os;
}

std::istream& operator>>(std::istream& is, MyString& obj) {
	char* buff = new char[obj.MAX_BUFFER_SIZE];
	is.getline(buff, obj.MAX_BUFFER_SIZE);
	obj.SetString(buff);
	return is;
}