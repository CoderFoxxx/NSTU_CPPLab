#include "null_ptr.h"

null_ptr::null_ptr(void* what) {
	std::stringstream stream;
	stream << "Null-Pointer reference at address " << what;
	sprintf((char*)message_, "%s", stream.str().c_str());
}

null_ptr::null_ptr(const char* message) : message_(message) {}

const char* null_ptr::what() const noexcept {
	return message_;
}