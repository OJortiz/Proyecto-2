#include "pch.h"
#include "Inventario.h"
#include "Proveedor.h"

generic <typename T>
Inventario<T>::Inventario()
{
    CantidadStock = 0;
    FechaCaducidad = DateTime::Now;
    Proveedor = nullptr;
    PrecioCompra = 0.0;
    PrecioVenta = 0.0;
}

generic <typename T>
Inventario<T>::Inventario(int cantidadStock, DateTime fechaCaducidad, Medicamento<T>^ proveedor, double precioCompra, double precioVenta)
{
    CantidadStock = cantidadStock;
    FechaCaducidad = fechaCaducidad;
    Proveedor = proveedor;
    PrecioCompra = precioCompra;
    PrecioVenta = precioVenta;
}