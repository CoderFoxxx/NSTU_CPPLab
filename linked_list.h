#pragma once
#include "node.h"
#include "my_string.h"

template<class T>
class LinkedList
{
public:
	LinkedList() : head_(nullptr) {}

	~LinkedList() {
		Node<T> *current = head_;
		while (current != nullptr) {
			Node<T> *next = current->next;
			delete current;
			current = next;
		}
	}

	void Add(T* item) {
		Node<T> *node = new Node<T>(item);
		node->next = head_;
		head_ = node;
	}

	void RemoveAt(unsigned int idx) {
		Node<T> *current = head_;
		Node<T> *prev = nullptr;
		int i = 0;

		while (current != nullptr && i != idx) {
			prev = current;
			current = current->next;
			i++;
		}

		if (current == nullptr) {
			throw std::out_of_range("Index out of range");
		}

		if (prev != nullptr) {
			prev->next = current->next;
		}
		else {
			head_ = current->next;
		}
	}

	void InsertAt(unsigned int idx, T* item) {
		unsigned int i = 0;
		Node<T> *current = head_;
		while (i < idx && current->next) {
			current = current->next;
			i++;
		}

		Node<T> *temp = new Node(item);
		if (current->next != nullptr) temp->next = current->next;
		else temp->next = nullptr;
		current->next = temp;
	}

	char* c_str() {
		std::stringstream stream;
		Node<T> *current = head_;
		while (current != nullptr) {
			stream << *current->data << "->";
			current = current->next;
		}
		char* str = new char[strlen(stream.str().c_str()) + 1];
		sprintf(str, "%s", stream.str().c_str());
		return str;
	}

	T* Find(T val) {
		Node<T> *current = head_;
		int idx = 0;
		T* result = new T[MAX_ENTRIES];
		for (int i = 0; i < MAX_ENTRIES; ++i) {
			result[i] = new T;
		}

		while (current != nullptr) {
			if (*current->data == val) {
				result[idx++] = *current->data;
			}
			current = current->next;
		}

		return result;
	}
private:
	Node<T> *head_;
	const int MAX_ENTRIES = 5;

	friend std::ostream& operator<<(std::ostream& os, LinkedList& obj) {
		os << obj.c_str();
		return os;
	}
};

template<>
MyString* LinkedList<MyString>::Find(MyString val) {
	Node<MyString> *current = head_;
	int idx = 0;
	MyString* result = new MyString[MAX_ENTRIES];
	for (int i = 0; i < MAX_ENTRIES; ++i) {
		result[i] = *(new MyString(""));
	}
	while (current != nullptr) {
		if (current->data->Contains(val.GetString())) {
			result[idx++] = *current->data;
		}
		current = current->next;
	}

	return result;
}