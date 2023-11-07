#pragma once

using namespace System;
using namespace System::Collections::Generic;

generic <typename T>
ref class Medicamento
{
public:
	String^ Nombre;
	String^ NumRegistro;
	String^ Categoria;
	List<String^>^ PrincipiosA;
	String^ Dosis;

	Medicamento();
	Medicamento(String^ nombre, String^ numRegistro, String^ categoria, List<String^>^ principiosActivos, String^ dosisRecomendada);

};

