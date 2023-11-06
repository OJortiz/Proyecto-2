#pragma once
#include "Node.h"

generic <typename T>
public ref class ListaDE
{
public:
    ListaDE();
    ~ListaDE();

    void Add(T value);
    bool Remove(T value);
    void Clear();

    property int Count {
        int get();
    }

    T GetAt(int index);
    T GetFirst();
    T GetLast();

private:
    Node<T>^ head;
    Node<T>^ tail;
    int count;

};




