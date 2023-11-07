#include "pch.h"
#include "Medicamento.h"

generic <typename T>
Medicamento<T>::Medicamento()
{
    Nombre = nullptr;
    NumRegistro = nullptr;
    Categoria = nullptr;
    PrincipiosA = gcnew List<String^>();
    Dosis = nullptr;
}

generic <typename T>
Medicamento<T>::Medicamento(String^ nombre, String^ numRegistro, String^ categoria, List<String^>^ principiosActivos, String^ dosisRecomendada)
{
    Nombre = nombre;
    NumRegistro = numRegistro;
    Categoria = categoria;
    PrincipiosA = principiosActivos;
    Dosis = dosisRecomendada;
}
