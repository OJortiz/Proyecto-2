#include "pch.h"
#include "ListaDE.h"
#include "Medicamento.h"
#include "Inventario.h"
#include "Proveedor.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;


void IngresarMed(ListaDE<Medicamento<String^>^>^ listaMedicamentos, ListaDE<Inventario<String^>^>^ inventario, ListaDE<Proveedor<String^>^>^ proveedorList) {

    // Solicitar al usuario que ingrese los datos del medicamento
    Console::WriteLine("Ingrese los datos del medicamento:");
    Console::Write("Nombre: ");
    String^ nombre = Console::ReadLine();
    Console::Write("Número de Registro: ");
    int numRegistro = Convert::ToInt32(Console::ReadLine());
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
    int fechaCaducidad = Convert::ToInt32(Console::ReadLine());
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

    Proveedor<String^>^ Newproveedor = gcnew Proveedor<String^>(nombreProveedor, "ProveedorID", direccionProveedor, direccionProveedor, telefonoProveedor, "proveedor@example.com",numRegistro);
    Inventario<String^>^ nuevoInventario = gcnew Inventario<String^>(cantidadStock, fechaCaducidad, Newproveedor, precioCompra, precioVenta,numRegistro);
    inventario->Add(nuevoInventario);
    proveedorList->Add(Newproveedor);

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
        Console::WriteLine("Número de Registro: " + medicamento->NumRegistro);

        // Solicitar al usuario que ingrese los nuevos detalles
        Console::WriteLine("Ingrese los nuevos detalles del medicamento:");
        Console::Write("Número de Registro: ");
        int nuevoNumRegistro = Convert::ToInt32(Console::ReadLine());

        // Actualizar los detalles del medicamento
        medicamento->NumRegistro = nuevoNumRegistro;

        // Mostrar mensaje de actualización exitosa
        Console::WriteLine("El medicamento se ha actualizado exitosamente.");
    }
    else
    {
        Console::WriteLine("El medicamento no se encontró en la lista.");
    }
}

void PromedioDePreciosDeVenta(ListaDE<Inventario<String^>^>^ inventario) {
    List<Inventario<String^>^>^ InventarioCurrent = gcnew List<Inventario<String^>^>();
    int cantidad = inventario->Count;
    Node<Inventario<String^>^>^ current = inventario->GetFirstNode();
    int SumaValores = 0;
    int ValorPromedioVenta;
    while (current != nullptr) {
        InventarioCurrent->Add(current->value);
        current = current->next;
    }
    if (InventarioCurrent->Count > 0) {
        for each (Inventario<String^> ^ precioventa in InventarioCurrent) {
            SumaValores = SumaValores + precioventa->PrecioVenta;
        }

        if (cantidad > 0) {
            ValorPromedioVenta = SumaValores / cantidad;
            Console::WriteLine("EL valor promedio de las medicinas ofrecidas es de: " + ValorPromedioVenta + "");
        }
    }
    else
    {
        Console::WriteLine("Aun no hay valores ingresados :D");
    }
    return;

    }

void MostrarValoresDeInventario(ListaDE<Medicamento<String^>^>^ listaMedicamentos, ListaDE<Inventario<String^>^>^ inventario) {
    Console::Write("Ingrese el nombre del medicamento que desea buscar: ");
    String^ consulta = Console::ReadLine();
    // Obttiene el medicamento

    List<Medicamento<String^>^>^ listaMedicamentosLista = gcnew List<Medicamento<String^>^>();
    Node<Medicamento<String^>^>^ currentMed = listaMedicamentos->GetFirstNode();
    List<Inventario<String^>^>^ InventarioCurrent = gcnew List<Inventario<String^>^>();
    Node<Inventario<String^>^>^ currentInv = inventario->GetFirstNode();

    while (currentMed != nullptr) {
        listaMedicamentosLista->Add(currentMed->value);
        currentMed = currentMed->next;
    }

    while (currentInv != nullptr) {
        InventarioCurrent->Add(currentInv->value);
        currentInv = currentInv->next;
    }
    int reg = 0;
    if (listaMedicamentosLista->Count > 0)
    {
        for each (Medicamento<String^> ^ med in listaMedicamentosLista)
        {
            if (med->Nombre == consulta)
            {
                reg = med->NumRegistro;
            }
        }
    }
    else
    {
        Console::WriteLine("No se encontraron medicamentos que coincidan con la consulta.");
    }
    if (InventarioCurrent->Count > 0)
    {
        for each (Inventario<String^> ^ med in InventarioCurrent)
        {
            med->NumRegistro;
            if (med->NumRegistro == reg)
            {
                Console::WriteLine("Detalles actuales de inventario del medicamento:");
                Console::WriteLine("Cantidad en stock: " + med->CantidadStock);
                Console::WriteLine("Fecha de caducidad: " + med->FechaCaducidad);
                Console::WriteLine("Proveedor Asociado: " + med->ProveedorAsociado);
                Console::WriteLine("Precio de compra: " + med->PrecioCompra);
                Console::WriteLine("Precio de venta: " + med->PrecioVenta);

            }
        }
    }
    else
    {
        Console::WriteLine("Error de registro");
    }
}

void ConsultarMedicamentoMasCaroDeProveedor(ListaDE<Medicamento<String^>^>^ listaMedicamentos, ListaDE<Inventario<String^>^>^ inventario, ListaDE<Proveedor<String^>^>^ Proveedores) {
    List<Medicamento<String^>^>^ listaMedicamentosLista = gcnew List<Medicamento<String^>^>();
    Node<Medicamento<String^>^>^ currentMed = listaMedicamentos->GetFirstNode();
    List<Inventario<String^>^>^ InventarioCurrent = gcnew List<Inventario<String^>^>();
    Node<Inventario<String^>^>^ currentInv = inventario->GetFirstNode();
    List<Proveedor<String^>^>^ ProveedoresCurrent = gcnew List<Proveedor<String^>^>();
    Node<Proveedor<String^>^>^ currentProveedor = Proveedores->GetFirstNode();
    Console::Write("Ingrese el proveedor que desea consultar: ");
    String^ consulta = Console::ReadLine();
    double CurrentRegMax = 0;
    double CurrentMaxPrice = 0;
    String^ MedicinaMasCara = "";
    int numReg;
    while (currentMed != nullptr) {
        listaMedicamentosLista->Add(currentMed->value);
        currentMed = currentMed->next;
    }

    while (currentInv != nullptr) {
        InventarioCurrent->Add(currentInv->value);
        currentInv = currentInv->next;
    }

    while (currentProveedor != nullptr) {
        ProveedoresCurrent->Add(currentProveedor->value);
        currentProveedor = currentProveedor->next;
    }
    if (ProveedoresCurrent->Count > 0)
    {
        for each (Proveedor<String^> ^ proveedor in ProveedoresCurrent)
        {
            if (proveedor->Nombre == consulta)
            {
                numReg = proveedor->NumRegistro;
                if (listaMedicamentosLista->Count > 0) {
                    for each (Medicamento<String^> ^ med in listaMedicamentosLista)
                    {
                        if (numReg == med->NumRegistro) {
                            if (InventarioCurrent->Count > 0) {
                                for each (Inventario<String^> ^ Invent in InventarioCurrent)
                                {
                                    if (numReg == Invent->NumRegistro){
                                        if (Invent->PrecioCompra > CurrentMaxPrice) {
                                            CurrentMaxPrice = Invent->PrecioCompra;
                                            CurrentRegMax = numReg;
                                            for each (Medicamento<String^> ^ med in listaMedicamentosLista)
                                            {
                                                if (CurrentRegMax = med->NumRegistro) {
                                                    MedicinaMasCara = med->Nombre;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                                
                        }
                    }
                }
            }
        }
        Console::WriteLine("La medicina del proveedor " + consulta + " mas cara es: " + MedicinaMasCara+", con un precio de "+CurrentMaxPrice);
    }
    else 
    {
        Console::WriteLine("No existen proveedores");
    }
}

void ConsultarMedicamento(ListaDE<Medicamento<String^>^>^ listaMedicamentos)
{
    Console::Write("Ingrese el nombre o principio activo del medicamento que desea buscar: ");
    String^ consulta = Console::ReadLine();
    // Obtén la lista de medicamentos
  
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
                Console::WriteLine("Número de Registro: " + med->NumRegistro);
                Console::WriteLine("Categoría: " + med->Categoria);
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

void BuscarMedicamentoPorCategoria(ListaDE<Medicamento<String^>^>^ listaMedicamentos)
{
    Console::Write("Ingrese la categoría del medicamento que desea buscar: ");
    String^ consulta = Console::ReadLine();
    // Obtén la lista de medicamentos

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
            if (med->Categoria->Equals(consulta, StringComparison::CurrentCultureIgnoreCase))
            {
                Console::WriteLine("Nombre: " + med->Nombre);
                Console::WriteLine("Categoría: " + med->Categoria);
                Console::WriteLine();
            }
        }
    }
    else
    {
        Console::WriteLine("No se encontraron medicamentos que coincidan con la consulta.");
    }
}

void BuscarMedicamentoPorPrincipioActivo(ListaDE<Medicamento<String^>^>^ listaMedicamentos)
{
    Console::Write("Ingrese el principio activo del medicamento que desea buscar: ");
    String^ consulta = Console::ReadLine();
    // Obtén la lista de medicamentos

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
            if (med->PrincipiosA->Contains(consulta))
            {
                Console::WriteLine("Nombre: " + med->Nombre);
                Console::WriteLine("Principios Activos:");
                for each (String ^ principioActivo in med->PrincipiosA)
                {
                    Console::WriteLine("   - " + principioActivo);
                }
                Console::WriteLine("Categoría: " + med->Categoria);
                Console::WriteLine();
            }
        }
    }
    else
    {
        Console::WriteLine("No se encontraron medicamentos que coincidan con la consulta.");
    }
}



ref class MedicamentoComparer : public System::Collections::Generic::IComparer<Medicamento<String^>^>
{
public:
    virtual int Compare(Medicamento<String^>^ med1, Medicamento<String^>^ med2)
    {
        return med1->Nombre->CompareTo(med2->Nombre);
    }
};
void GenerarInformeMedicamentos(ListaDE<Medicamento<String^>^>^ listaMedicamentos)
{
    // Crear una lista ordenada de medicamentos por nombre
    List<Medicamento<String^>^>^ medicamentosOrdenados = gcnew List<Medicamento<String^>^>();
    Node<Medicamento<String^>^>^ current = listaMedicamentos->GetFirstNode();

    while (current != nullptr) {
        medicamentosOrdenados->Add(current->value);
        current = current->next;
    }

    MedicamentoComparer^ comparer = gcnew MedicamentoComparer();
    medicamentosOrdenados->Sort(comparer);

    // Mostrar el informe por consola
    Console::WriteLine("Informe de Medicamentos:");
    for each (Medicamento<String^> ^ med in medicamentosOrdenados) {
        Console::WriteLine("Nombre: " + med->Nombre);
        Console::WriteLine("Número de Registro: " + med->NumRegistro);
        Console::WriteLine("Categoría: " + med->Categoria);
        Console::WriteLine("Principios Activos:");
        for each (String ^ principioActivo in med->PrincipiosA) {
            Console::WriteLine("   - " + principioActivo);
        }
        Console::WriteLine("Dosis Recomendada: " + med->Dosis);
        Console::WriteLine();
    }

    // Nombre del archivo CSV
    String^ fileName = "InformeMedicamentos.csv";

    // Crear y abrir el archivo CSV
    StreamWriter^ writer = gcnew StreamWriter(fileName);

    // Escribir la primera línea con los encabezados
    writer->WriteLine("Nombre,Numero de Registro,Categoria,Principios Activos,Dosis Recomendada");

    // Iterar sobre los medicamentos ordenados y escribir cada uno en una línea
    for each (Medicamento<String^> ^ med in medicamentosOrdenados) {
        String^ principios = String::Join(", ", med->PrincipiosA);
        writer->WriteLine(med->Nombre + "," + med->NumRegistro + "," + med->Categoria + "," + principios + "," + med->Dosis);

    }

    // Cerrar el archivo
    writer->Close();

    // Mostrar un mensaje indicando que el informe ha sido exportado
    Console::WriteLine(String::Format("Informe exportado a {0}", fileName));

}


int main(array<System::String ^> ^args)
{

    int opcion;
    bool salir = false;
    String^ respuesta = " ";

    ListaDE<Medicamento<String^>^>^ listaMedicamentos = gcnew ListaDE<Medicamento<String^>^>();
    ListaDE<Inventario<String^>^>^ inventario = gcnew ListaDE<Inventario<String^>^>();
    ListaDE<Proveedor<String^>^>^ proveedorList = gcnew ListaDE<Proveedor<String^>^>();


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
            do {
                IngresarMed(listaMedicamentos, inventario, proveedorList);

                // Preguntar al usuario si desea ingresar un nuevo medicamento o regresar al menú
                Console::Write("¿Desea ingresar un nuevo medicamento? (S/N): ");
                respuesta = Console::ReadLine();

                if (respuesta != nullptr && respuesta->Equals("N", StringComparison::CurrentCultureIgnoreCase)) {
                    break; // Si el usuario no desea ingresar más medicamentos, salir del bucle.
                }
            } while (true);
            break;

        case 2:
            ActualizarMedicamento(listaMedicamentos, inventario);
            break;

        case 3:
            ConsultarMedicamento(listaMedicamentos);
            break;

        case 4:
            GenerarInformeMedicamentos(listaMedicamentos);
            break;

        case 5:
            PromedioDePreciosDeVenta(inventario);
            break;

        case 6:
            MostrarValoresDeInventario(listaMedicamentos, inventario);
            break;

        case 7:
            ConsultarMedicamentoMasCaroDeProveedor(listaMedicamentos, inventario, proveedorList);
            break;

        case 9:
            salir = true;
            break;
        }
    }
        while (!salir);
    return 0;
}
