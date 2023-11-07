#pragma once
#include "Medicamento.h"

using namespace System;
using namespace System::Collections::Generic;

generic <typename T>
ref class Inventario
{
    int CantidadStock;
    DateTime FechaCaducidad;
    Medicamento<T>^ Proveedor;
    double PrecioCompra;
    double PrecioVenta;

    Inventario();
    Inventario(int cantidadStock, DateTime fechaCaducidad, Medicamento<T>^ proveedor, double precioCompra, double precioVenta);
};

