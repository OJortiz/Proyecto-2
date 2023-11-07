#include "pch.h"
#include "Proveedor.h"

#include "Proveedor.h"

generic <typename T>
Proveedor<T>::Proveedor()
{
    Nombre = nullptr;
    NT = nullptr;
    DireccionFiscal = nullptr;
    DireccionContacto = nullptr;
    Telefono = nullptr;
    EMail = nullptr;
}

generic <typename T>
Proveedor<T>::Proveedor(String^ nombre, String^ nt, String^ direccionFiscal, String^ direccionContacto, String^ telefono, String^ correoElectronico)
{
    Nombre = nombre;
    NT = nt;
    DireccionFiscal = direccionFiscal;
    DireccionContacto = direccionContacto;
    Telefono = telefono;
    EMail = correoElectronico;
}
