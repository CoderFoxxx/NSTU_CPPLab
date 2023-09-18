#pragma once
class MyString
{
public:
	MyString(int init_len);
	MyString();
	MyString(MyString& other);
	~MyString();

	const char* GetString() const;
	int GetMaxLength() const;
	int GetLength() const;
	void SetString(const char* new_str);
	void SetMaxLength(int new_max_len);
	void SetLength(int new_len);

	bool Contains(const char* sub) const;
	char* c_str();

	static int string_cnt;
private:
	char* str_;
	int max_len_;
	int str_len_;
};
