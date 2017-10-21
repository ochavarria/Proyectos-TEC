#pragma once


using namespace System::Drawing::Drawing2D;
using namespace System::Drawing;

public ref class VerticeGrafico 
{
public:

	VerticeGrafico()
	{
		forma = gcnew GraphicsPath();
	}

	void a�adir(array<Point>^ puntos)
	{
		forma->AddLines(puntos);
		forma->CloseFigure();
	}
	System::String^ nombre;
	GraphicsPath^ forma;
	Color color;

	
};