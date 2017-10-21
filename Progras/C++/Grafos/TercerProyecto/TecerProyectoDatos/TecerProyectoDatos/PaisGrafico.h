#pragma once


using namespace System::Drawing::Drawing2D;
using namespace System::Drawing;

public ref class PaisGrafico 
{
public:
	PaisGrafico(int pcodigo ,int x, int y)
	{
		codigo = pcodigo;
		posicion = Point(x, y);
		cuadroImagen = gcnew System::Windows::Forms::PictureBox();
		System::String^ ruta = L"banderas/" + System::Convert::ToString(codigo) + ".png";
		cuadroImagen->Image = dynamic_cast<Image^>(gcnew Bitmap(ruta));
		cuadroImagen->Location = Point(x-10,y-10);
		cuadroImagen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		cuadroImagen->Visible = true;
	}
	
	int codigo;
	Point posicion;
	System::Windows::Forms::PictureBox^  cuadroImagen;


	

	
};