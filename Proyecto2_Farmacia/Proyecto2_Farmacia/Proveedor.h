#pragma once

using namespace System;
generic <typename T>
ref class Proveedor
{
public:
    String^ Nombre;
    String^ NT;
    String^ DireccionFiscal;
    String^ DireccionContacto;
    String^ Telefono;
    String^ EMail;
    property int NumRegistro;


    Proveedor();
    Proveedor(String^ nombre, String^ nt, String^ direccionFiscal, String^ direccionContacto, String^ telefono, String^ EMail, int NumRegistro);

};

