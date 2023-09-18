#include <iostream>
#include <fstream>
#include <string>

#include "my_string.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL, "");
	int initial_len;
	cout << "Введите длину строки: ";
	cin >> initial_len;
	cin.ignore();
	char* str_in = new char[initial_len];
	cout << "Введите строку: ";
	cin.getline(str_in, initial_len);
	MyString str(initial_len);
	str.SetString(str_in);
	cout << str.c_str() << ". Количество строк: " << MyString::string_cnt << endl;
	if (str.Contains("World")) {
		cout << "Эта строка содержит подстроку \"World\"" << std::endl;
	}
	else {
		cout << "Эта строка не содержит подстроки \"World\"";
	}

	delete[] str_in;
	return 0;
}