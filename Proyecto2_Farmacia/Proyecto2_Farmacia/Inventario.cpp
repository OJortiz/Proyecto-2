#include "pch.h"
#include "Inventario.h"

using namespace System;

generic <typename T>
Inventario<T>::Inventario()
{
    CantidadStock = 0;
    FechaCaducidad = 0;
    ProveedorAsociado = nullptr;
    PrecioCompra = 0.0;
    PrecioVenta = 0.0;
}

generic <typename T>
Inventario<T>::Inventario(int cantidadStock, int fechaCaducidad, Proveedor<T>^ proveedorAsociado, double precioCompra, double precioVenta)
{
    CantidadStock = cantidadStock;
    FechaCaducidad = fechaCaducidad;
    ProveedorAsociado = proveedorAsociado; // Corregido el nombre de la propiedad
    PrecioCompra = precioCompra;
    PrecioVenta = precioVenta;
}
