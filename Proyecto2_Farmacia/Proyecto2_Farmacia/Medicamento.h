#pragma once

using namespace System;
using namespace System::Collections::Generic;

generic <typename T>
ref class Medicamento
{
public:
	String^ Nombre;
	int NumRegistro;
	String^ Categoria;
	List<String^>^ PrincipiosA;
	String^ Dosis;

	Medicamento();
	Medicamento(String^ nombre, int numRegistro, String^ categoria, List<String^>^ principiosActivos, String^ dosisRecomendada);

};

