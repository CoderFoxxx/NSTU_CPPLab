#pragma once
#include "my_string.h"

template<class T>
class Node
{
public:
	Node(T* item) : data(item), next(nullptr) {}
	T* data;
	Node* next;
};