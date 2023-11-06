#include "pch.h"
#include "ListaDE.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    ListaDE<int>^ lista = gcnew ListaDE<int>();

    lista->Add(10);
    lista->Add(20);
    lista->Add(30);
    lista->Add(40);

    Console::WriteLine("Elementos en la lista:");
    for (int i = 0; i < lista->Count; i++) {
        Console::WriteLine(lista->GetAt(i));
    }

    Console::WriteLine("\nPrimer elemento: " + lista->GetFirst());
    Console::WriteLine("Último elemento: " + lista->GetLast());

    if (lista->Remove(20)) {
        Console::WriteLine("\nElemento 20 eliminado.");
    }

    Console::WriteLine("\nElementos en la lista después de eliminar 20:");
    for (int i = 0; i < lista->Count; i++) {
        Console::WriteLine(lista->GetAt(i));
    }

    lista->Clear();
    Console::WriteLine("\nLista borrada. Número de elementos: " + lista->Count);
    return 0;
}
