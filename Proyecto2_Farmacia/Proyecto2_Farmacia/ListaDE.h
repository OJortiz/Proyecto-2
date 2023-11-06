#pragma once
#include "Node.h"

template <typename T>
ref class ListaDE
{
	Node<T>^ head;

public:

	int count;

	ListaDE() {
		count = 0;
		head = nullptr;
	}

};




