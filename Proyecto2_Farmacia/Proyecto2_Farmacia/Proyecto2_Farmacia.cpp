#include "pch.h"
#include "ListaDE.h"
#include "Medicamento.h"
#include "Inventario.h"
#include "Proveedor.h"

using namespace System;
using namespace System::Collections::Generic;

int main(array<System::String ^> ^args)
{

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

            ListaDE<Medicamento<String^>^>^ listaMedicamentos = gcnew ListaDE<Medicamento<String^>^>();
            ListaDE<Inventario<String^>^>^ inventario = gcnew ListaDE<Inventario<String^>^>();

            // Solicitar al usuario que ingrese los datos del medicamento
            Console::WriteLine("Ingrese los datos del medicamento:");
            Console::Write("Nombre: ");
            String^ nombre = Console::ReadLine();
            Console::Write("Número de Registro: ");
            String^ numRegistro = Console::ReadLine();
            Console::Write("Categoría: ");
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
            Console::Write("Número de Teléfono del Proveedor: ");
            String^ telefonoProveedor = Console::ReadLine();
            Console::Write("Dirección de Contacto del Proveedor: ");
            String^ direccionProveedor = Console::ReadLine();

            Proveedor<String^>^ proveedor = gcnew Proveedor<String^>(nombreProveedor, "ProveedorID", direccionProveedor, direccionProveedor, telefonoProveedor, "proveedor@example.com");
            Inventario<String^>^ nuevoInventario = gcnew Inventario<String^>(cantidadStock, fechaCaducidad, proveedor, precioCompra, precioVenta);
            inventario->Add(nuevoInventario);

            // Mostrar la información del medicamento y su inventario
            Console::WriteLine("\nInformación del Medicamento registrado:");
            Console::WriteLine("Nombre: " + nuevoMedicamento->Nombre);
            Console::WriteLine("Número de Registro: " + nuevoMedicamento->NumRegistro);
            Console::WriteLine("Categoría: " + nuevoMedicamento->Categoria);
            Console::WriteLine("Principios Activos:");

            for each (String ^ principioActivo in nuevoMedicamento->PrincipiosA) {
                Console::WriteLine("   - " + principioActivo);
            }

            Console::WriteLine("Dosis Recomendada: " + nuevoMedicamento->Dosis);
            Console::WriteLine();

            Console::WriteLine("Información del Inventario del Medicamento:");
            Console::WriteLine("Cantidad en Stock: " + nuevoInventario->CantidadStock);
            Console::WriteLine("Fecha de Caducidad: " + nuevoInventario->FechaCaducidad.ToString("yyyy-MM-dd"));
            Console::WriteLine("Proveedor: " + nuevoInventario->ProveedorAsociado->Nombre);
            Console::WriteLine("Precio de Compra: " + nuevoInventario->PrecioCompra);
            Console::WriteLine("Precio de Venta: " + nuevoInventario->PrecioVenta);


        }


    }
        while (!salir);
    return 0;
}
