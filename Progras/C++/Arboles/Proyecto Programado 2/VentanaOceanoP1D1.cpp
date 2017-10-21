#include "VentanaOceanoP1D1.h"

System::Void VentanaOceanoP1D1::botonbuscar_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(login)
	{
		string textobusqueda = convertirSystemString(textobuscar->Text->ToString());
		DatoDiccionario* resultadobusqueda = _diccionario->buscar(textobusqueda);
		if (resultadobusqueda)
		{
			tbresultado->Text = convertirStdString(resultadobusqueda->definicion);
			tbSinonimos->Text = convertirStdString(resultadobusqueda->sinonimo);
			tbresultado->Visible = true;
			tbSinonimos->Visible = true;
			etiquetaDefinicion->Visible = true;
			etiquetaSinonimos->Visible = true;
		}
		else
		{
			tbSinonimos->Visible = false;
			etiquetaDefinicion->Visible = false;
			etiquetaSinonimos->Visible = false;
			tbresultado->Visible = true;
			tbresultado->Text = "El contenido que solicito no esta disponible";
		}
	}
	else
	{
		mensajeSesion();
	}
}

System::Void VentanaOceanoP1D1::buscarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	limpiarPanelBusqueda();
	panelModificarTexto->Visible = false;
	panelBusqueda->Visible = true;
}

System::Void  VentanaOceanoP1D1::modificarTextoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(login)
	{
		dialogoAbrir->FileName = "";
		dialogoAbrir->ShowDialog();
		if (dialogoAbrir->FileName != "")
		{
			tbTexto->Text = "";
			panelBusqueda->Visible = false;
			panelModificarTexto->Visible = true;
			lNombreTexto->Text = dialogoAbrir->SafeFileName;
			string ruta = convertirSystemString(dialogoAbrir->FileName);
			_texto->abrirTexto(ruta);
			linfoTexto->Text = "El Texto Posee " + convertirStdString(intToString(_texto->cantidadPalabras())) + " palabras";
			cargarTextoAlLabel();
		}
	}
	else
	{
		mensajeSesion();
	}
}

System::Void  VentanaOceanoP1D1::bByR_Click(System::Object^  sender, System::EventArgs^  e)
{

	if (tbPalabra->Text != "")
	{
		cambiable = true;
		if (bByR->Text == "Buscar")
		{
			//Info de Repeticiones
			int repeticiones = infoRepeticionPalabra();
			primera = true;
			if (repeticiones != 0)
			{
				posicionModificacion = 0;
				//LLenar Sinonimos
				llenarComboxSinonimos();
				//Resaltar en Texto
				resaltarTexto(posicionModificacion);
				bByR->Text = "Reemplazar";
				bSiguiente->Visible = true;
			}
		}
		else
		{
			bool siguiente = false;
			if (bByR->Text == "Reemplazar")
			{
				if (cbSinonimos->Text != "")
				{
					_texto->modificar(convertirSystemString(tbPalabra->Text), convertirSystemString(cbSinonimos->Text),primera);
					primera = false;
					siguiente=avanzarMod();
					refrecarTexto(!siguiente);					
				}
			}
		}
	}

}

System::Void  VentanaOceanoP1D1::bSiguiente_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool siguiente =avanzarMod();
	if (posicionModificacion != -1)
	{
		string palabra = convertirSystemString(tbPalabra->Text);
		_texto->modificar(palabra, palabra, primera);
		primera = false;
		refrecarTexto(!siguiente);
	}
	else
	{
		limpiarMod();
	}
}

void VentanaOceanoP1D1::refrecarTexto(bool limpiar)
{
	cargarTextoAlLabel();
	resaltarTexto(posicionModificacion);
	int repeticiones = infoRepeticionPalabra();
	if (limpiar)
		limpiarMod();
}

void VentanaOceanoP1D1::limpiarMod()
{
	cbSinonimos->Items->Clear();
	cbSinonimos->Text = "";
	tbPalabra->Text = "";
	bByR->Text = "Buscar";
	bSiguiente->Visible = false;
	lrepeticiones->Visible = false;
	
}

bool VentanaOceanoP1D1::avanzarMod()
{
	posicionModificacion = tbTexto->Find(tbPalabra->Text, posicionModificacion, tbTexto->TextLength, RichTextBoxFinds::WholeWord);
	if (posicionModificacion > 0)
		posicionModificacion++;
	int siguiente = tbTexto->Find(tbPalabra->Text, posicionModificacion, tbTexto->TextLength, RichTextBoxFinds::WholeWord);
	if (siguiente != -1)
		return true;
	else
		return false;

}

System::Void VentanaOceanoP1D1::bGuardar_Click(System::Object^  sender, System::EventArgs^  e)
{
	dialogoGuardar->FileName = "";
	dialogoGuardar->ShowDialog();
	_texto->guardar( convertirSystemString(dialogoGuardar->FileName));
}

System::Void VentanaOceanoP1D1::tbPalabra_TextChanged(System::Object^  sender, System::EventArgs^  e) 
{
	if (cambiable)
	{
		limpiarMod();
		cargarTextoAlLabel();
		cambiable = false;
	}
}

void VentanaOceanoP1D1::limpiarPanelBusqueda()
{
	textobuscar->Text = "";
	tbresultado->Text = "";
	tbSinonimos->Text = "";
	tbresultado->Visible = false;
	tbSinonimos->Visible = false;
	etiquetaDefinicion->Visible = false;
	etiquetaSinonimos->Visible = false;
}

void VentanaOceanoP1D1::cargarTextoAlLabel()
{
	tbTexto->Clear();
	DatoTexto* resultado = _texto->getPalabraTexto(true);
	while (resultado)
	{
		string palabra;
		palabra = resultado->separacionatras + resultado->palabra;
		tbTexto->Text = tbTexto->Text + convertirStdString(palabra);
		resultado = _texto->getPalabraTexto(false);
	}
}

void VentanaOceanoP1D1::llenarComboxSinonimos()
{
	cbSinonimos->Items->Clear();
	cbSinonimos->Text = "";
	string textobusqueda = convertirSystemString(tbPalabra->Text);
	string letraincial = "";
	letraincial = letraincial + textobusqueda[0];
	DatoDiccionario* resultadobusqueda = _diccionario->buscar(textobusqueda);
	if (resultadobusqueda)
		cbSinonimos->Items->Add(convertirStdString(resultadobusqueda->sinonimo));
}

void VentanaOceanoP1D1::resaltarTexto(int pPosicion)
{
	int indice = pPosicion;
	int largo = tbTexto->TextLength;
	while (indice!=-1)
	{
		indice=tbTexto->Find(tbPalabra->Text, indice, largo, RichTextBoxFinds::WholeWord);
		tbTexto->SelectionBackColor = Color::Yellow;
		if (indice > 0)
			indice++;
	}
}

int VentanaOceanoP1D1::infoRepeticionPalabra()
{
	lrepeticiones->Visible = true;
	string textobusqueda = convertirSystemString(tbPalabra->Text);
	int repeticiones = _texto->repeticionesPalabra(textobusqueda);
	lrepeticiones->Text = "Esta palabra se repite "+convertirStdString(intToString(repeticiones))+" veces";
	return repeticiones;
}

string VentanaOceanoP1D1::convertirSystemString(String^ pDato)
{
	msclr::interop::marshal_context context;
	string resultado = context.marshal_as<std::string>(pDato);
	return resultado;
}

String^ VentanaOceanoP1D1::convertirStdString(string pDato)
{
	String^ resultado = gcnew String(pDato.c_str());
	return resultado;
}

string VentanaOceanoP1D1::intToString(int pInt)
{
	string resultado;
	ostringstream lineastream;
	lineastream << pInt;
	resultado = lineastream.str();
	return resultado;
}