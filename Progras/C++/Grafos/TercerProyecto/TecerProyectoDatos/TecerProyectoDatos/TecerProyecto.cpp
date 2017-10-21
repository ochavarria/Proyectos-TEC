#include "TecerProyecto.h"



System::Void TecerProyecto::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	continente->mapa->dibujar();
}

System::Void TecerProyecto::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	consola->Text=continente->colorear();
	continente->mapa->pintar(false);
	continente->mapa->dibujar();
}
System::Void TecerProyecto::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	continente->cargarSegundaParte();
}
