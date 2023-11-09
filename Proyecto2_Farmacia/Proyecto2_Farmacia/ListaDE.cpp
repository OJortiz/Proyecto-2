#include "pch.h"

#include "ListaDE.h"

using namespace System;

generic <typename T>
ListaDE<T>::ListaDE()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

generic <typename T>
ListaDE<T>::~ListaDE()
{
    Clear();
}

generic <typename T>
void ListaDE<T>::Add(T value)
{
    Node<T>^ newNode = gcnew Node<T>(value);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    count++;
}

generic <typename T>
bool ListaDE<T>::Remove(T value)
{
    Node<T>^ current = head;

    while (current != nullptr) {
        if (current->value->Equals(value)) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }

            count--;
            return true;
        }

        current = current->next;
    }

    return false;
}

generic <typename T>
void ListaDE<T>::Clear()
{
    while (head != nullptr) {
        Node<T>^ temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    count = 0;
}
generic <typename T>
int ListaDE<T>::Count::get()
{
    return count;
}

generic <typename T>
T ListaDE<T>::GetAt(int index)
{
    if (index < 0 || index >= count)
        throw gcnew ArgumentOutOfRangeException("index");

    Node<T>^ current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->value;
}

generic <typename T>
T ListaDE<T>::GetFirst()
{
    if (head != nullptr)
        return head->value;

    throw gcnew InvalidOperationException("The list is empty.");
}

generic <typename T>
Node<T>^ ListaDE<T>::GetFirstNode()
{
    if (head != nullptr)
        return head;

    return nullptr;
}


generic <typename T>
T ListaDE<T>::GetLast()
{
    if (tail != nullptr)
        return tail->value;

    throw gcnew InvalidOperationException("The list is empty.");
}

generic <typename T>
T ListaDE<T>::GetSumaRecorrer() {
    Node<T>^ current = head; 
    T valor;
    while (current != nullptr && current !=tail)
    {
        valor = current->value;
        current = current->next;

    }
    return valor;

}
generic <typename T>
ListaDE<T>^ ListaDE<T>::ObtenerLista()
{
    ListaDE<T>^ lista = gcnew ListaDE<T>();
    Node<T>^ current = head;

    while (current != nullptr)
    {
        lista->Add(current->value);
        current = current->next;
    }

    return lista;
}
