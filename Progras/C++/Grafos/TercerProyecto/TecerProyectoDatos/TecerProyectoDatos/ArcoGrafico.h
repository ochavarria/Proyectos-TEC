#pragma once


using namespace System::Drawing::Drawing2D;
using namespace System::Drawing;

public ref class ArcoGrafico
{
public:

	ArcoGrafico()
	{
		forma = gcnew GraphicsPath();
	}

	void crear(Point inicio,Point pfinal)
	{
		array<Point>^ puntos = { inicio, pfinal };
		forma->AddLines(puntos);
		forma->CloseFigure();
	}
	GraphicsPath^ forma;


};