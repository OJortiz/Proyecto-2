#include "pch.h"
#include "ListaDE.h"
#include "Medicamento.h"
#include "Inventario.h"
#include "Proveedor.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Diagnostics;


void IngresarMed(ListaDE<Medicamento<String^>^>^ listaMedicamentos, ListaDE<Inventario<String^>^>^ inventario, ListaDE<Proveedor<String^>^>^ proveedorList) {
    bool confirmar = true;
    String^ nombre;
    int numRegistro;
    String^ categoria;
    // Solicitar al usuario que ingrese los datos del medicamento
    do {
        try
        {
            Console::WriteLine("Ingrese los datos del medicamento:");
            Console::Write("Nombre: ");
            nombre = Console::ReadLine();
            Console::Write("Número de Registro: ");
            numRegistro = Convert::ToInt32(Console::ReadLine());
            Console::Write("Categoría: ");
            categoria = Console::ReadLine();
            confirmar = false;
        }
        catch(Exception ^ ex)
        {
            Console::Write("Un valor ingresado es invalido, ingrese nuevamente ");
        }
    }
    while (confirmar == true);
    String^ principiosActivosInput;
    String^ dosisRecomendada;
    List<String^>^ principiosActivos;
    do {
        try
        {
    principiosActivos = gcnew List<String^>();
    Console::Write("Principios Activos (separados por comas): ");
    principiosActivosInput = Console::ReadLine();
    array<String^>^ principios = principiosActivosInput->Split(',');
    principiosActivos->AddRange(principios);
    Console::Write("Dosis Recomendada: ");
    dosisRecomendada = Console::ReadLine();
    confirmar = true;
        }
        catch (Exception^ ex)
        {
            Console::Write("Un valor ingresado es invalido, ingrese nuevamente ");
        }
    } while (confirmar == false);

    Medicamento<String^>^ nuevoMedicamento = gcnew Medicamento<String^>(nombre, numRegistro, categoria, principiosActivos, dosisRecomendada);
    listaMedicamentos->Add(nuevoMedicamento);
    int cantidadStock;
    DateTime fechaCaducidad;
    double precioCompra;
    double precioVenta;
    do {
        try
        {
    // Solicitar al usuario que ingrese los datos del inventario
    Console::WriteLine("\nIngrese los datos del inventario del medicamento:");
    Console::Write("Cantidad en Stock: ");
    cantidadStock = Convert::ToInt32(Console::ReadLine());
    Console::Write("Fecha de Caducidad (yyyy-MM-dd): ");
    fechaCaducidad = DateTime::Parse(Console::ReadLine());
    Console::Write("Precio de Compra: ");
    precioCompra = Convert::ToDouble(Console::ReadLine());
    Console::Write("Precio de Venta: ");
    precioVenta = Convert::ToDouble(Console::ReadLine());
    confirmar = false;
        }
        catch (Exception^ ex)
        {
            Console::Write("Un valor ingresado es invalido, ingrese nuevamente ");
        }
    } while (confirmar == true);
    String^ nombreProveedor;
    String^ telefonoProveedor;
    String^ direccionProveedor;
    do {
        try
        {
    Console::Write("Proveedor: ");
    nombreProveedor = Console::ReadLine();
    Console::Write("Número de Teléfono del Proveedor: ");
    telefonoProveedor = Console::ReadLine();
    Console::Write("Dirección de Contacto del Proveedor: ");
    direccionProveedor = Console::ReadLine();
    confirmar = true;
        }
        catch (Exception^ ex)
        {
            Console::Write("Un valor ingresado es invalido, ingrese nuevamente ");
        }
    } while (confirmar == false);
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
    String^ nombreMedicamento;
    bool confirmar = true;
    do {
        try {
            nombreMedicamento = Console::ReadLine();
            confirmar = false;
        }
        catch (Exception^ ex)
        {
            Console::Write("Un valor ingresado es invalido, ingrese nuevamente ");
        }
    } while (confirmar == true);

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
        Console::WriteLine("Categoria: " + medicamento->Categoria);
        Console::WriteLine("Principios Activos:");
        for each (String ^ principioActivo in medicamento->PrincipiosA) {
            Console::WriteLine("   - " + principioActivo);
        }
        Console::WriteLine("Dosis: " + medicamento->Dosis);

        // Mostrar las opciones de actualización
        Console::WriteLine("Seleccione qué desea actualizar:");
        Console::WriteLine("1. Número de Registro");
        Console::WriteLine("2. Categoría");
        Console::WriteLine("3. Principios Activos");
        Console::WriteLine("4. Dosis");

        // Leer la opción del usuario
        Console::Write("Ingrese el número de la opción: ");
        int opcion;
        bool confirmarOpcion = false;
        do {
            try {
                opcion = Convert::ToInt32(Console::ReadLine());
                confirmarOpcion = true;
            }
            catch (Exception^ ex) {
                Console::Write("Opción inválida, ingrese nuevamente: ");
            }
        } while (!confirmarOpcion);

        // Realizar la actualización según la opción seleccionada
        switch (opcion) {
        case 1: {
            // Actualizar el número de registro
            Console::Write("Nuevo Número de Registro: ");
            int nuevoNumRegistro;
            bool confirm = false;
            do {
                try {
                    nuevoNumRegistro = Convert::ToInt32(Console::ReadLine());
                    confirm = true;
                }
                catch (Exception^ ex) {
                    Console::Write("Un valor ingresado es inválido, ingrese nuevamente ");
                }
            } while (!confirm);
            medicamento->NumRegistro = nuevoNumRegistro;
            break;
        }
        case 2: {
            // Actualizar la categoría
            Console::Write("Nueva Categoría: ");
            String^ nuevaCategoria = Console::ReadLine();
            medicamento->Categoria = nuevaCategoria;
            break;
        }
        case 3: {
            // Actualizar los principios activos
            Console::Write("Nuevos Principios Activos (separados por comas): ");
            String^ nuevosPrincipiosInput = Console::ReadLine();
            array<String^>^ nuevosPrincipios = nuevosPrincipiosInput->Split(',');
            medicamento->PrincipiosA->Clear();
            medicamento->PrincipiosA->AddRange(nuevosPrincipios);
            break;
        }
        case 4: {
            // Actualizar la dosis
            Console::Write("Nueva Dosis: ");
            String^ nuevaDosis = Console::ReadLine();
            medicamento->Dosis = nuevaDosis;
            break;
        }
        default:
            Console::WriteLine("Opción no válida.");
            break;
        }

        // Mostrar mensaje de actualización exitosa
        Console::WriteLine("El medicamento se ha actualizado exitosamente.");

    }
    else
    {
        Console::WriteLine("El medicamento no se encontró en la lista.");
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
    Console::WriteLine("Desea abrir el archivo? 1 = Si, 2 = No");
    int eleccion = Convert::ToInt32(Console::ReadLine());
    if (eleccion == 1) {
        try
        {
            Process^ proceso = gcnew Process();
            proceso->StartInfo->FileName = "notepad.exe"; // Establece el programa a utilizar (Bloc de notas en este caso)
            proceso->StartInfo->Arguments = fileName;     // Establece el archivo a abrir
            proceso->Start();
        }
        catch (Exception^ e)
        {
            Console::WriteLine("Error al abrir el archivo: " + e->Message);
        }

        Console::ReadLine(); // Espera a que el usuario presione Enter
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
    String^ consulta;
    bool verificar = false;
    do {
        try {
            consulta = Console::ReadLine();
            verificar = true;
        }
        catch (Exception^ ex)
        {
            Console::Write("Un valor ingresado es invalido, ingrese nuevamente ");
        }
    } while (verificar == false);
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
    String^ consulta;
    bool verificar = false;
    do {
        try {
            consulta = Console::ReadLine();
            verificar = true;
        }
        catch (Exception^ ex)
        {
            Console::Write("Un valor ingresado es invalido, ingrese nuevamente ");
        }
    } while (verificar == false);
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

void BuscarPorProveedor(ListaDE<Inventario<String^>^>^ inventario)
{
    Console::Write("Ingrese el nombre del proveedor que desea buscar: ");
    String^ consulta = Console::ReadLine();

    List<Inventario<String^>^>^ inventarioLista = gcnew List<Inventario<String^>^>();
    Node<Inventario<String^>^>^ current = inventario->GetFirstNode();

    while (current != nullptr)
    {
        inventarioLista->Add(current->value);
        current = current->next;
    }

    if (inventarioLista->Count > 0)
    {
        Console::WriteLine("Medicamentos por Proveedor encontrados:");
        for each (Inventario<String^> ^ inventarioMed in inventarioLista)
        {
            if (inventarioMed->ProveedorAsociado->Nombre->Equals(consulta, StringComparison::CurrentCultureIgnoreCase))
            {
                Console::WriteLine("Nombre del Proveedor: " + inventarioMed->ProveedorAsociado->Nombre);
                Console::WriteLine("Cantidad en Stock: " + inventarioMed->CantidadStock);
                Console::WriteLine("Fecha de Caducidad: " + inventarioMed->FechaCaducidad.ToString("yyyy-MM-dd"));
                Console::WriteLine("Precio de Compra: " + inventarioMed->PrecioCompra);
                Console::WriteLine("Precio de Venta: " + inventarioMed->PrecioVenta);
                Console::WriteLine();
            }
        }
    }
    else
    {
        Console::WriteLine("No se encontraron medicamentos asociados al proveedor que coincidan con la consulta.");
    }
}

void BuscarPorFecha(ListaDE<Inventario<String^>^>^ inventario) {
    Console::Write("Ingrese la fecha de caducidad (yyyy-MM-dd): ");
    String^ consulta = Console::ReadLine();

    if (DateTime::TryParseExact(consulta, "yyyy-MM-dd", CultureInfo::InvariantCulture, DateTimeStyles::None, DateTime()))

    {
        DateTime fechaCaducidad = DateTime::ParseExact(consulta, "yyyy-MM-dd", CultureInfo::InvariantCulture);

        List<Inventario<String^>^>^ inventarioLista = gcnew List<Inventario<String^>^>();
        Node<Inventario<String^>^>^ current = inventario->GetFirstNode();

        while (current != nullptr)
        {
            inventarioLista->Add(current->value);
            current = current->next;
        }

        if (inventarioLista->Count > 0)
        {
            Console::WriteLine("Medicamentos por Fecha encontrados:");
            for each (Inventario<String^> ^ inventarioMed in inventarioLista)
            {
                // Comparar la fecha de caducidad
                if (DateTime::Compare(inventarioMed->FechaCaducidad, fechaCaducidad) == 0)
                {
                    Console::WriteLine("Nombre del Proveedor: " + inventarioMed->ProveedorAsociado->Nombre);
                    Console::WriteLine("Cantidad en Stock: " + inventarioMed->CantidadStock);
                    Console::WriteLine("Fecha de Caducidad: " + inventarioMed->FechaCaducidad.ToString("yyyy-MM-dd"));
                    Console::WriteLine("Precio de Compra: " + inventarioMed->PrecioCompra);
                    Console::WriteLine("Precio de Venta: " + inventarioMed->PrecioVenta);
                    Console::WriteLine();
                }
            }
        }
        else
        {
            Console::WriteLine("No se encontraron medicamentos asociados a la fecha que coincidan con la consulta.");
        }
    }
    else
    {
        Console::WriteLine("Formato de fecha incorrecto. Use el formato yyyy-MM-dd.");
    }
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

        case 8:
            Console::WriteLine("Selecciona el criterio de búsqueda:");
            Console::WriteLine("1. Por categoría");
            Console::WriteLine("2. Por principio activo");
            Console::WriteLine("3. Por proveedor");
            Console::WriteLine("4. Por fecha de caducidad");

            int criterio;
            if (!Int32::TryParse(Console::ReadLine(), criterio)) {
                Console::WriteLine("Error: Ingresa un número válido.");
                break;
            }

            switch (criterio)
            {
            case 1:
                BuscarMedicamentoPorCategoria(listaMedicamentos);
                break;

            case 2:
                BuscarMedicamentoPorPrincipioActivo(listaMedicamentos);
                break;

            case 3:
                BuscarPorProveedor(inventario);
                break;

            case 4:
                BuscarPorFecha(inventario);
                break;

            default:
                Console::WriteLine("Opción no válida.");
                break;
            }

            break;

        case 9:
            Console::WriteLine("Ha salido del sistema de Datos de la Farmacia");
            salir = true;
            break;
        }
    }
        while (!salir);
    return 0;
}
