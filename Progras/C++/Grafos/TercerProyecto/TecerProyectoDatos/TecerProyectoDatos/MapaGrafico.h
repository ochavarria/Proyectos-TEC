#pragma once

#include  "VerticeGrafico.h"

using namespace System::Drawing;
using namespace System::Collections::Generic;

public ref class MapaGrafico
{
public:

	MapaGrafico()
	{
		pincel = gcnew SolidBrush(Color::Silver);
		pluma = gcnew Pen(Color::Black);
		partes = gcnew List<VerticeGrafico^>();
	}

	List<VerticeGrafico^>^ partes;
	Graphics^ areaDeDibujo;

	SolidBrush^ pincel;
	Pen^ pluma;

	void pintar(bool dormir)
	{
		for (int contador = 0; contador < partes->Count; contador++)
		{
			pincel->Color = partes[contador]->color;
			areaDeDibujo->FillPath(pincel, partes[contador]->forma);
			if(dormir)
				System::Threading::Thread::Sleep(350);
		}
	}

	void dibujar()
	{
		for (int contador = 0; contador < partes->Count; contador++)
		{
			areaDeDibujo->DrawPath(gcnew Pen(Color::Black), partes[contador]->forma);
		}	
	}

	
};