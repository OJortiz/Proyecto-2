#include "pch.h"
#include "ListaDE.h"
#include "Medicamento.h"
#include "Inventario.h"
#include "Proveedor.h"

using namespace System;
using namespace System::Collections::Generic;


void IngresarMed(ListaDE<Medicamento<String^>^>^ listaMedicamentos, ListaDE<Inventario<String^>^>^ inventario) {

    // Solicitar al usuario que ingrese los datos del medicamento
    Console::WriteLine("Ingrese los datos del medicamento:");
    Console::Write("Nombre: ");
    String^ nombre = Console::ReadLine();
    Console::Write("N�mero de Registro: ");
    String^ numRegistro = Console::ReadLine();
    Console::Write("Categor�a: ");
    String^ categoria = Console::ReadLine();

    List<String^>^ principiosActivos = gcnew List<String^>();
    Console::Write("Principios Activos (separados por comas): ");
    String^ principiosActivosInput = Console::ReadLine();
    array<String^>^ principios = principiosActivosInput->Split(',');
    principiosActivos->AddRange(principios);

    Console::Write("Dosis Recomendada: ");
    String^ dosisRecomendada = Console::ReadLine();

    Medicamento<String^>^ nuevoMedicamento = gcnew Medicamento<String^>(nombre, numRegistro, categoria, principiosActivos, dosisRecomendada);
    listaMedicamentos->Add(nuevoMedicamento);

    // Solicitar al usuario que ingrese los datos del inventario
    Console::WriteLine("\nIngrese los datos del inventario del medicamento:");
    Console::Write("Cantidad en Stock: ");
    int cantidadStock = Convert::ToInt32(Console::ReadLine());
    Console::Write("Fecha de Caducidad (yyyy-MM-dd): ");
    DateTime fechaCaducidad = DateTime::ParseExact(Console::ReadLine(), "yyyy-MM-dd", nullptr);
    Console::Write("Precio de Compra: ");
    double precioCompra = Convert::ToDouble(Console::ReadLine());
    Console::Write("Precio de Venta: ");
    double precioVenta = Convert::ToDouble(Console::ReadLine());

    Console::Write("Proveedor: ");
    String^ nombreProveedor = Console::ReadLine();
    Console::Write("N�mero de Tel�fono del Proveedor: ");
    String^ telefonoProveedor = Console::ReadLine();
    Console::Write("Direcci�n de Contacto del Proveedor: ");
    String^ direccionProveedor = Console::ReadLine();

    Proveedor<String^>^ proveedor = gcnew Proveedor<String^>(nombreProveedor, "ProveedorID", direccionProveedor, direccionProveedor, telefonoProveedor, "proveedor@example.com");
    Inventario<String^>^ nuevoInventario = gcnew Inventario<String^>(cantidadStock, fechaCaducidad, proveedor, precioCompra, precioVenta);
    inventario->Add(nuevoInventario);

    // Mostrar la informaci�n del medicamento y su inventario
    Console::WriteLine("\nInformaci�n del Medicamento registrado:");
    Console::WriteLine("Nombre: " + nuevoMedicamento->Nombre);
    Console::WriteLine("N�mero de Registro: " + nuevoMedicamento->NumRegistro);
    Console::WriteLine("Categor�a: " + nuevoMedicamento->Categoria);
    Console::WriteLine("Principios Activos:");

    for each (String ^ principioActivo in nuevoMedicamento->PrincipiosA) {
        Console::WriteLine("   - " + principioActivo);
    }

    Console::WriteLine("Dosis Recomendada: " + nuevoMedicamento->Dosis);
    Console::WriteLine();

    Console::WriteLine("Informaci�n del Inventario del Medicamento:");
    Console::WriteLine("Cantidad en Stock: " + nuevoInventario->CantidadStock);
    Console::WriteLine("Fecha de Caducidad: " + nuevoInventario->FechaCaducidad.ToString("yyyy-MM-dd"));
    Console::WriteLine("Proveedor: " + nuevoInventario->ProveedorAsociado->Nombre);
    Console::WriteLine("Precio de Compra: " + nuevoInventario->PrecioCompra);
    Console::WriteLine("Precio de Venta: " + nuevoInventario->PrecioVenta);
}

void ActualizarMedicamento(ListaDE<Medicamento<String^>^>^ listaMedicamentos, ListaDE<Inventario<String^>^>^ inventario) {
    Console::Write("Ingrese el nombre del medicamento a actualizar: ");
    String^ nombreMedicamento = Console::ReadLine();

    Node<Medicamento<String^>^>^ current = listaMedicamentos->GetFirstNode();
    Medicamento<String^>^ medicamento = nullptr;

    while (current != nullptr)
    {
        if (current->value->Nombre == nombreMedicamento)
        {
            medicamento = current->value;
            break;
        }
        current = current->next;
    }

    if (medicamento != nullptr)
    {
        // Mostrar los detalles actuales del medicamento
        Console::WriteLine("Detalles actuales del medicamento:");
        Console::WriteLine("Nombre: " + medicamento->Nombre);
        Console::WriteLine("N�mero de Registro: " + medicamento->NumRegistro);

        // Solicitar al usuario que ingrese los nuevos detalles
        Console::WriteLine("Ingrese los nuevos detalles del medicamento:");
        Console::Write("N�mero de Registro: ");
        String^ nuevoNumRegistro = Console::ReadLine();

        // Actualizar los detalles del medicamento
        medicamento->NumRegistro = nuevoNumRegistro;

        // Mostrar mensaje de actualizaci�n exitosa
        Console::WriteLine("El medicamento se ha actualizado exitosamente.");
    }
    else
    {
        Console::WriteLine("El medicamento no se encontr� en la lista.");
    }
}

void ConsultarMedicamento(ListaDE<Medicamento<String^>^>^ listaMedicamentos)
{
    Console::Write("Ingrese el nombre o principio activo del medicamento que desea buscar: ");
    String^ consulta = Console::ReadLine();
    // Obt�n la lista de medicamentos
  
    List<Medicamento<String^>^>^ listaMedicamentosLista = gcnew List<Medicamento<String^>^>();
    Node<Medicamento<String^>^>^ current = listaMedicamentos->GetFirstNode();

    while (current != nullptr) {
        listaMedicamentosLista->Add(current->value);
        current = current->next;
    }

    if (listaMedicamentosLista->Count > 0)
    {
        Console::WriteLine("Medicamentos encontrados:");
        for each (Medicamento<String^> ^ med in listaMedicamentosLista)
        {
            if (med->Nombre == consulta || med->PrincipiosA->Contains(consulta))
            {
                Console::WriteLine("Nombre: " + med->Nombre);
                Console::WriteLine("N�mero de Registro: " + med->NumRegistro);
                Console::WriteLine("Categor�a: " + med->Categoria);
                Console::WriteLine("Principios Activos:");
                for each (String ^ principioActivo in med->PrincipiosA)
                {
                    Console::WriteLine("   - " + principioActivo);
                }
                Console::WriteLine("Dosis Recomendada: " + med->Dosis);
                Console::WriteLine();
            }
        }
    }
    else
    {
        Console::WriteLine("No se encontraron medicamentos que coincidan con la consulta.");
    }
}

int main(array<System::String ^> ^args)
{

    int opcion;
    bool salir = false;
    String^ respuesta = " ";

    ListaDE<Medicamento<String^>^>^ listaMedicamentos = gcnew ListaDE<Medicamento<String^>^>();
    ListaDE<Inventario<String^>^>^ inventario = gcnew ListaDE<Inventario<String^>^>();


    do {
        Console::WriteLine("1. Registro de nuevos medicamentos y su inventario");
        Console::WriteLine("2. Actualizaci�n de detalles de los medicamentos y su disponibilidad en el inventario.");
        Console::WriteLine("3. Consulta de informaci�n sobre un medicamento espec�fico por el nombre o principio activo.");
        Console::WriteLine("4. Generaci�n de informes sobre los medicamentos");
        Console::WriteLine("5. Calcular el precio promedio de todos los medicamentos disponibles en farmacia.");
        Console::WriteLine("6. Dado el nombre de un medicamento, mostrar sus datos de inventario.");
        Console::WriteLine("7. Dado un proveedor conocer el medicamento con el precio m�s alto que distribuye a la farmacia.");
        Console::WriteLine("8. B�squeda y filtrado de medicamentos por diferentes criterios (por ejemplo, por categor�a, por principio activo, por proveedor, por fecha de caducidad).");
        Console::WriteLine("9. Salir ");

        if (!Int32::TryParse(Console::ReadLine(), opcion)) {
            Console::WriteLine("Error: Ingresa un numero valido.");
            continue;
        }

        switch (opcion)
        {
        case 1:
            IngresarMed(listaMedicamentos, inventario);

            // Preguntar al usuario si desea ingresar un nuevo medicamento o regresar al men�
            Console::Write("�Desea ingresar un nuevo medicamento? (S/N): ");
            respuesta = Console::ReadLine();

            if (respuesta != nullptr && respuesta->Equals("N", StringComparison::CurrentCultureIgnoreCase)) {
                salir = true; // Si el usuario no desea ingresar m�s medicamentos, salir del bucle.
            }
            break;

        case 2:
            ActualizarMedicamento(listaMedicamentos, inventario);
            break;

        case 3:
            ConsultarMedicamento(listaMedicamentos);
            break;

        case 4:
            break;

        }
    }
        while (!salir);
    return 0;
}
