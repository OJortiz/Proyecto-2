#pragma once
#include "Medicamento.h"
#include "Proveedor.h"

using namespace System;
using namespace System::Collections::Generic;

generic <typename T>
public ref class Inventario
{
public:
    property int CantidadStock;
    property DateTime FechaCaducidad;
    property Proveedor<T>^ ProveedorAsociado;
    property double PrecioCompra;
    property double PrecioVenta;

    Inventario();
    Inventario(int cantidadStock, DateTime fechaCaducidad, Proveedor<T>^ proveedorAsociado, double precioCompra, double precioVenta);
};
