#include "pch.h"
#include "ListaDE.h"
#include "Medicamento.h"

using namespace System;
using namespace System::Collections::Generic;

int main(array<System::String ^> ^args)
{
    ListaDE<Medicamento<String^>^>^ listaMedicamentos = gcnew ListaDE<Medicamento<String^>^>();

    // Crear medicamentos y agregarlos a la lista
    List<String^>^ principiosActivos1 = gcnew List<String^>();
    principiosActivos1->Add("Paracetamol");
    principiosActivos1->Add("Ibuprofeno");
    Medicamento<String^>^ medicamento1 = gcnew Medicamento<String^>("Medicamento1", "12345", "Venta libre", principiosActivos1, "2 tabletas cada 6 horas");

    List<String^>^ principiosActivos2 = gcnew List<String^>();
    principiosActivos2->Add("Aspirina");
    principiosActivos2->Add("Cafeína");
    Medicamento<String^>^ medicamento2 = gcnew Medicamento<String^>("Medicamento2", "67890", "Venta con receta", principiosActivos2, "1 tableta cada 8 horas");

    listaMedicamentos->Add(medicamento1);
    listaMedicamentos->Add(medicamento2);

    // Mostrar información de los medicamentos en la lista
    Console::WriteLine("Medicamentos en la lista:");
    for (int i = 0; i < listaMedicamentos->Count; i++) {
        Medicamento<String^>^ medicamento = listaMedicamentos->GetAt(i);
        Console::WriteLine("Nombre: " + medicamento->Nombre);
        Console::WriteLine("Número de Registro: " + medicamento->NumRegistro);
        Console::WriteLine("Categoría: " + medicamento->Categoria);
        Console::WriteLine("Principios Activos:");

        for each (String ^ principioActivo in medicamento->PrincipiosA) {
            Console::WriteLine("   - " + principioActivo);
        }

        Console::WriteLine("Dosis Recomendada: " + medicamento->Dosis);
        Console::WriteLine();
    }

    int opcion;
    bool salir = false;

    do {
        Console::WriteLine("1. Registro de nuevos medicamentos y su inventario");
        Console::WriteLine("2. Actualización de detalles de los medicamentos y su disponibilidad en el inventario.");
        Console::WriteLine("3. Consulta de información sobre un medicamento específico por el nombre o principio activo.");
        Console::WriteLine("4. Generación de informes sobre los medicamentos");
        Console::WriteLine("5. Calcular el precio promedio de todos los medicamentos disponibles en farmacia.");
        Console::WriteLine("6. Dado el nombre de un medicamento, mostrar sus datos de inventario.");
        Console::WriteLine("7. Dado un proveedor conocer el medicamento con el precio más alto que distribuye a la farmacia.");
        Console::WriteLine("8. Búsqueda y filtrado de medicamentos por diferentes criterios (por ejemplo, por categoría, por principio activo, por proveedor, por fecha de caducidad).");
        Console::WriteLine("9. Salir ");

        if (!Int32::TryParse(Console::ReadLine(), opcion)) {
            Console::WriteLine("Error: Ingresa un numero valido.");
            continue;
        }

        switch (opcion)
        {
        case 1:
            Console::WriteLine("aaaaaaaa");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            Console::WriteLine("Ha salido del programa");
            salir = true;
            break;
        default:
            break;
        }


    }
        while (!salir);
    return 0;
}
