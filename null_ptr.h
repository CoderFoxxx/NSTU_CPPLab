#pragma once
#include <iostream>
#include <sstream>

class null_ptr : public std::exception
{
public:
	null_ptr(void* what);
	null_ptr(const char* message);
	const char* what() const noexcept override;
private:
	const char* message_ = (const char*)new char[128];
};

