
#include <msclr\marshal_cppstd.h>
#include "sstream"
#include  "Diccionario.h"
#include "Texto.h"
#include "Conversor.h"
#include <msclr/marshal_cppstd.h>

using std::ostringstream;
using std::string;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



public ref class VentanaOceanoP1D1 : public System::Windows::Forms::Form
{
public:
	VentanaOceanoP1D1(void)
	{
		cambiable = false;
		primera = true;
		posicionModificacion = 0;
		login=false;
		
		_texto = new Texto();

		InitializeComponent();
		//
		//TODO: agregar código de constructor aquí
		//
		
		int msgboxID = MessageBoxA(NULL, "¿Desea cargar los archivos fuente?", "Archivos Fuente", MB_OKCANCEL);
		string palabras="";
		string abecedario="";
		string estudiantes="";
		string sinonimos="";
		string definiciones="";
		switch (msgboxID)
		{
		case IDOK:
			dialogoAbrir->Title = "Abecedario";
			dialogoAbrir->ShowDialog();
			abecedario = convertirSystemString(dialogoAbrir->FileName);
			dialogoAbrir->FileName = "";
			dialogoAbrir->Title = "Palabras";
			dialogoAbrir->ShowDialog();
			palabras = convertirSystemString(dialogoAbrir->FileName);
			dialogoAbrir->FileName = "";
			dialogoAbrir->Title = "Definiciones";
			dialogoAbrir->ShowDialog();
			definiciones = convertirSystemString(dialogoAbrir->FileName);
			dialogoAbrir->FileName = "";
			dialogoAbrir->Title = "Sinonimos";
			dialogoAbrir->ShowDialog();
			sinonimos = convertirSystemString(dialogoAbrir->FileName);
			dialogoAbrir->FileName = "";
			dialogoAbrir->Title = "Estudiantes";
			dialogoAbrir->ShowDialog();
			estudiantes = convertirSystemString(dialogoAbrir->FileName);
			dialogoAbrir->Title = "";
			dialogoAbrir->FileName = "";
			_diccionario = new Diccionario(abecedario,palabras,sinonimos,definiciones,estudiantes);
			break;
		default:
			_diccionario = new Diccionario();
			break;
		}
		
	}

protected:

	~VentanaOceanoP1D1()
	{
		if (components)
		{
			delete components;
		}
	}

private: System::Windows::Forms::Button^  botonbuscar;
private: System::Windows::Forms::Label^  lbuscar;
private: System::Windows::Forms::TextBox^  textobuscar;


private:

	bool cambiable;
	bool primera;
	bool login;
	int posicionModificacion;
	Diccionario* _diccionario;
	Texto* _texto;

	System::Windows::Forms::TextBox^  tbresultado;
	System::Windows::Forms::Label^  etiquetaDefinicion;
	System::Windows::Forms::Label^  etiquetaSinonimos;
	System::Windows::Forms::TextBox^  tbSinonimos;
	System::Windows::Forms::Label^  etiquiteInfo1;


private: System::Windows::Forms::Panel^  panelBusqueda;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^  inicioToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  buscarToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  modificarTextoToolStripMenuItem;
private: System::Windows::Forms::Panel^  panelModificarTexto;
private: System::Windows::Forms::OpenFileDialog^  dialogoAbrir;
private: System::Windows::Forms::Button^  bByR;
private: System::Windows::Forms::TextBox^  tbPalabra;




private: System::Windows::Forms::ComboBox^  cbSinonimos;

private: System::Windows::Forms::RichTextBox^  tbTexto;
private: System::Windows::Forms::Label^  lRemplazo;

private: System::Windows::Forms::Label^  lMBuscar;

private: System::Windows::Forms::Label^  linfoTexto;
private: System::Windows::Forms::Label^  lNombreTexto;
private: System::Windows::Forms::Label^  lrepeticiones;

private: System::Windows::Forms::SaveFileDialog^  dialogoGuardar;
private: System::Windows::Forms::Button^  bGuardar;
private: System::Windows::Forms::Button^  bSiguiente;
private: System::Windows::Forms::Panel^  pUsuario;

private: System::Windows::Forms::Button^  bInicio;

private: System::Windows::Forms::TextBox^  tbUsuario;
private: System::Windows::Forms::Label^  lUsuario;




	System::ComponentModel::Container ^components;

	void InitializeComponent(void)
	{
		this->botonbuscar = (gcnew System::Windows::Forms::Button());
		this->lbuscar = (gcnew System::Windows::Forms::Label());
		this->textobuscar = (gcnew System::Windows::Forms::TextBox());
		this->tbresultado = (gcnew System::Windows::Forms::TextBox());
		this->etiquetaDefinicion = (gcnew System::Windows::Forms::Label());
		this->etiquetaSinonimos = (gcnew System::Windows::Forms::Label());
		this->tbSinonimos = (gcnew System::Windows::Forms::TextBox());
		this->etiquiteInfo1 = (gcnew System::Windows::Forms::Label());
		this->panelBusqueda = (gcnew System::Windows::Forms::Panel());
		this->pUsuario = (gcnew System::Windows::Forms::Panel());
		this->bInicio = (gcnew System::Windows::Forms::Button());
		this->tbUsuario = (gcnew System::Windows::Forms::TextBox());
		this->lUsuario = (gcnew System::Windows::Forms::Label());
		this->panelModificarTexto = (gcnew System::Windows::Forms::Panel());
		this->bSiguiente = (gcnew System::Windows::Forms::Button());
		this->bGuardar = (gcnew System::Windows::Forms::Button());
		this->lrepeticiones = (gcnew System::Windows::Forms::Label());
		this->linfoTexto = (gcnew System::Windows::Forms::Label());
		this->lNombreTexto = (gcnew System::Windows::Forms::Label());
		this->lRemplazo = (gcnew System::Windows::Forms::Label());
		this->lMBuscar = (gcnew System::Windows::Forms::Label());
		this->tbTexto = (gcnew System::Windows::Forms::RichTextBox());
		this->bByR = (gcnew System::Windows::Forms::Button());
		this->tbPalabra = (gcnew System::Windows::Forms::TextBox());
		this->cbSinonimos = (gcnew System::Windows::Forms::ComboBox());
		this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
		this->inicioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->buscarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->modificarTextoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->dialogoAbrir = (gcnew System::Windows::Forms::OpenFileDialog());
		this->dialogoGuardar = (gcnew System::Windows::Forms::SaveFileDialog());
		this->panelBusqueda->SuspendLayout();
		this->pUsuario->SuspendLayout();
		this->panelModificarTexto->SuspendLayout();
		this->menuStrip1->SuspendLayout();
		this->SuspendLayout();
		// 
		// botonbuscar
		// 
		this->botonbuscar->Location = System::Drawing::Point(475, 82);
		this->botonbuscar->Name = L"botonbuscar";
		this->botonbuscar->Size = System::Drawing::Size(57, 25);
		this->botonbuscar->TabIndex = 0;
		this->botonbuscar->Text = L"Buscar";
		this->botonbuscar->UseVisualStyleBackColor = true;
		this->botonbuscar->Click += gcnew System::EventHandler(this, &VentanaOceanoP1D1::botonbuscar_Click);
		// 
		// lbuscar
		// 
		this->lbuscar->AutoSize = true;
		this->lbuscar->Location = System::Drawing::Point(217, 58);
		this->lbuscar->Name = L"lbuscar";
		this->lbuscar->Size = System::Drawing::Size(79, 13);
		this->lbuscar->TabIndex = 1;
		this->lbuscar->Text = L"Buscar Palabra";
		// 
		// textobuscar
		// 
		this->textobuscar->Location = System::Drawing::Point(220, 85);
		this->textobuscar->Name = L"textobuscar";
		this->textobuscar->Size = System::Drawing::Size(249, 20);
		this->textobuscar->TabIndex = 2;
		// 
		// tbresultado
		// 
		this->tbresultado->BackColor = System::Drawing::SystemColors::MenuBar;
		this->tbresultado->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->tbresultado->ForeColor = System::Drawing::SystemColors::ControlText;
		this->tbresultado->Location = System::Drawing::Point(230, 168);
		this->tbresultado->Multiline = true;
		this->tbresultado->Name = L"tbresultado";
		this->tbresultado->ReadOnly = true;
		this->tbresultado->Size = System::Drawing::Size(249, 50);
		this->tbresultado->TabIndex = 3;
		this->tbresultado->Visible = false;
		// 
		// etiquetaDefinicion
		// 
		this->etiquetaDefinicion->AutoSize = true;
		this->etiquetaDefinicion->Location = System::Drawing::Point(227, 144);
		this->etiquetaDefinicion->Name = L"etiquetaDefinicion";
		this->etiquetaDefinicion->Size = System::Drawing::Size(54, 13);
		this->etiquetaDefinicion->TabIndex = 4;
		this->etiquetaDefinicion->Text = L"Definicion";
		this->etiquetaDefinicion->Visible = false;
		// 
		// etiquetaSinonimos
		// 
		this->etiquetaSinonimos->AutoSize = true;
		this->etiquetaSinonimos->Location = System::Drawing::Point(227, 234);
		this->etiquetaSinonimos->Name = L"etiquetaSinonimos";
		this->etiquetaSinonimos->Size = System::Drawing::Size(55, 13);
		this->etiquetaSinonimos->TabIndex = 5;
		this->etiquetaSinonimos->Text = L"Sinonimos";
		this->etiquetaSinonimos->Visible = false;
		// 
		// tbSinonimos
		// 
		this->tbSinonimos->BackColor = System::Drawing::SystemColors::MenuBar;
		this->tbSinonimos->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->tbSinonimos->ForeColor = System::Drawing::SystemColors::ControlText;
		this->tbSinonimos->Location = System::Drawing::Point(230, 259);
		this->tbSinonimos->Multiline = true;
		this->tbSinonimos->Name = L"tbSinonimos";
		this->tbSinonimos->ReadOnly = true;
		this->tbSinonimos->Size = System::Drawing::Size(249, 34);
		this->tbSinonimos->TabIndex = 6;
		this->tbSinonimos->Visible = false;
		// 
		// etiquiteInfo1
		// 
		this->etiquiteInfo1->AutoSize = true;
		this->etiquiteInfo1->Location = System::Drawing::Point(217, 113);
		this->etiquiteInfo1->Name = L"etiquiteInfo1";
		this->etiquiteInfo1->Size = System::Drawing::Size(98, 13);
		this->etiquiteInfo1->TabIndex = 7;
		this->etiquiteInfo1->Text = L"El Dicionario posee";
		// 
		// panelBusqueda
		// 
		this->panelBusqueda->Controls->Add(this->pUsuario);
		this->panelBusqueda->Controls->Add(this->botonbuscar);
		this->panelBusqueda->Controls->Add(this->tbSinonimos);
		this->panelBusqueda->Controls->Add(this->textobuscar);
		this->panelBusqueda->Controls->Add(this->etiquetaSinonimos);
		this->panelBusqueda->Controls->Add(this->etiquetaDefinicion);
		this->panelBusqueda->Controls->Add(this->tbresultado);
		this->panelBusqueda->Controls->Add(this->etiquiteInfo1);
		this->panelBusqueda->Controls->Add(this->lbuscar);
		this->panelBusqueda->Dock = System::Windows::Forms::DockStyle::Fill;
		this->panelBusqueda->Location = System::Drawing::Point(0, 0);
		this->panelBusqueda->Name = L"panelBusqueda";
		this->panelBusqueda->Size = System::Drawing::Size(625, 329);
		this->panelBusqueda->TabIndex = 10;
		// 
		// pUsuario
		// 
		this->pUsuario->Controls->Add(this->bInicio);
		this->pUsuario->Controls->Add(this->tbUsuario);
		this->pUsuario->Controls->Add(this->lUsuario);
		this->pUsuario->Location = System::Drawing::Point(3, 27);
		this->pUsuario->Name = L"pUsuario";
		this->pUsuario->Size = System::Drawing::Size(170, 69);
		this->pUsuario->TabIndex = 8;
		this->pUsuario->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VentanaOceanoP1D1::pUsuario_Paint);
		// 
		// bInicio
		// 
		this->bInicio->Location = System::Drawing::Point(33, 31);
		this->bInicio->Name = L"bInicio";
		this->bInicio->Size = System::Drawing::Size(100, 23);
		this->bInicio->TabIndex = 2;
		this->bInicio->Text = L"Iniciar Sesion";
		this->bInicio->UseVisualStyleBackColor = true;
		this->bInicio->Click += gcnew System::EventHandler(this, &VentanaOceanoP1D1::bInicio_Click);
		// 
		// tbUsuario
		// 
		this->tbUsuario->Location = System::Drawing::Point(61, 5);
		this->tbUsuario->Name = L"tbUsuario";
		this->tbUsuario->Size = System::Drawing::Size(100, 20);
		this->tbUsuario->TabIndex = 1;
		this->tbUsuario->TextChanged += gcnew System::EventHandler(this, &VentanaOceanoP1D1::tbUsuario_TextChanged);
		// 
		// lUsuario
		// 
		this->lUsuario->AutoSize = true;
		this->lUsuario->Location = System::Drawing::Point(12, 8);
		this->lUsuario->Name = L"lUsuario";
		this->lUsuario->Size = System::Drawing::Size(43, 13);
		this->lUsuario->TabIndex = 0;
		this->lUsuario->Text = L"Usuario";
		this->lUsuario->Click += gcnew System::EventHandler(this, &VentanaOceanoP1D1::lUsuario_Click);
		// 
		// panelModificarTexto
		// 
		this->panelModificarTexto->Controls->Add(this->bSiguiente);
		this->panelModificarTexto->Controls->Add(this->bGuardar);
		this->panelModificarTexto->Controls->Add(this->lrepeticiones);
		this->panelModificarTexto->Controls->Add(this->linfoTexto);
		this->panelModificarTexto->Controls->Add(this->lNombreTexto);
		this->panelModificarTexto->Controls->Add(this->lRemplazo);
		this->panelModificarTexto->Controls->Add(this->lMBuscar);
		this->panelModificarTexto->Controls->Add(this->tbTexto);
		this->panelModificarTexto->Controls->Add(this->bByR);
		this->panelModificarTexto->Controls->Add(this->tbPalabra);
		this->panelModificarTexto->Controls->Add(this->cbSinonimos);
		this->panelModificarTexto->Dock = System::Windows::Forms::DockStyle::Fill;
		this->panelModificarTexto->Location = System::Drawing::Point(0, 0);
		this->panelModificarTexto->Name = L"panelModificarTexto";
		this->panelModificarTexto->Size = System::Drawing::Size(625, 329);
		this->panelModificarTexto->TabIndex = 10;
		this->panelModificarTexto->Visible = false;
		// 
		// bSiguiente
		// 
		this->bSiguiente->Location = System::Drawing::Point(489, 225);
		this->bSiguiente->Name = L"bSiguiente";
		this->bSiguiente->Size = System::Drawing::Size(124, 23);
		this->bSiguiente->TabIndex = 12;
		this->bSiguiente->Text = L"Siguiente";
		this->bSiguiente->UseVisualStyleBackColor = true;
		this->bSiguiente->Visible = false;
		this->bSiguiente->Click += gcnew System::EventHandler(this, &VentanaOceanoP1D1::bSiguiente_Click);
		// 
		// bGuardar
		// 
		this->bGuardar->Location = System::Drawing::Point(258, 305);
		this->bGuardar->Name = L"bGuardar";
		this->bGuardar->Size = System::Drawing::Size(124, 21);
		this->bGuardar->TabIndex = 11;
		this->bGuardar->Text = L"Guardar";
		this->bGuardar->UseVisualStyleBackColor = true;
		this->bGuardar->Click += gcnew System::EventHandler(this, &VentanaOceanoP1D1::bGuardar_Click);
		// 
		// lrepeticiones
		// 
		this->lrepeticiones->AutoSize = true;
		this->lrepeticiones->Location = System::Drawing::Point(440, 114);
		this->lrepeticiones->Name = L"lrepeticiones";
		this->lrepeticiones->Size = System::Drawing::Size(0, 13);
		this->lrepeticiones->TabIndex = 10;
		// 
		// linfoTexto
		// 
		this->linfoTexto->AutoSize = true;
		this->linfoTexto->Location = System::Drawing::Point(11, 309);
		this->linfoTexto->Name = L"linfoTexto";
		this->linfoTexto->Size = System::Drawing::Size(47, 13);
		this->linfoTexto->TabIndex = 9;
		this->linfoTexto->Text = L"infotexto";
		this->linfoTexto->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// lNombreTexto
		// 
		this->lNombreTexto->AutoSize = true;
		this->lNombreTexto->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->lNombreTexto->Location = System::Drawing::Point(179, 32);
		this->lNombreTexto->Name = L"lNombreTexto";
		this->lNombreTexto->Size = System::Drawing::Size(47, 15);
		this->lNombreTexto->TabIndex = 8;
		this->lNombreTexto->Text = L"label1";
		this->lNombreTexto->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		// 
		// lRemplazo
		// 
		this->lRemplazo->AutoSize = true;
		this->lRemplazo->Location = System::Drawing::Point(408, 141);
		this->lRemplazo->Name = L"lRemplazo";
		this->lRemplazo->Size = System::Drawing::Size(75, 13);
		this->lRemplazo->TabIndex = 6;
		this->lRemplazo->Text = L"Remplazar por";
		// 
		// lMBuscar
		// 
		this->lMBuscar->AutoSize = true;
		this->lMBuscar->Location = System::Drawing::Point(440, 83);
		this->lMBuscar->Name = L"lMBuscar";
		this->lMBuscar->Size = System::Drawing::Size(43, 13);
		this->lMBuscar->TabIndex = 5;
		this->lMBuscar->Text = L"Palabra";
		// 
		// tbTexto
		// 
		this->tbTexto->BackColor = System::Drawing::SystemColors::Window;
		this->tbTexto->Location = System::Drawing::Point(12, 51);
		this->tbTexto->Name = L"tbTexto";
		this->tbTexto->ReadOnly = true;
		this->tbTexto->Size = System::Drawing::Size(368, 252);
		this->tbTexto->TabIndex = 4;
		this->tbTexto->Text = L"";
		// 
		// bByR
		// 
		this->bByR->Location = System::Drawing::Point(489, 196);
		this->bByR->Name = L"bByR";
		this->bByR->Size = System::Drawing::Size(124, 23);
		this->bByR->TabIndex = 2;
		this->bByR->Text = L"Buscar";
		this->bByR->UseVisualStyleBackColor = true;
		this->bByR->Click += gcnew System::EventHandler(this, &VentanaOceanoP1D1::bByR_Click);
		// 
		// tbPalabra
		// 
		this->tbPalabra->Location = System::Drawing::Point(489, 80);
		this->tbPalabra->Name = L"tbPalabra";
		this->tbPalabra->Size = System::Drawing::Size(128, 20);
		this->tbPalabra->TabIndex = 1;
		this->tbPalabra->TextChanged += gcnew System::EventHandler(this, &VentanaOceanoP1D1::tbPalabra_TextChanged);
		// 
		// cbSinonimos
		// 
		this->cbSinonimos->FormattingEnabled = true;
		this->cbSinonimos->Location = System::Drawing::Point(489, 138);
		this->cbSinonimos->Name = L"cbSinonimos";
		this->cbSinonimos->Size = System::Drawing::Size(128, 21);
		this->cbSinonimos->TabIndex = 0;
		// 
		// menuStrip1
		// 
		this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLight;
		this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->inicioToolStripMenuItem });
		this->menuStrip1->Location = System::Drawing::Point(0, 0);
		this->menuStrip1->Name = L"menuStrip1";
		this->menuStrip1->Size = System::Drawing::Size(625, 24);
		this->menuStrip1->TabIndex = 11;
		this->menuStrip1->Text = L"menuStrip1";
		// 
		// inicioToolStripMenuItem
		// 
		this->inicioToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
			this->buscarToolStripMenuItem,
				this->modificarTextoToolStripMenuItem
		});
		this->inicioToolStripMenuItem->Name = L"inicioToolStripMenuItem";
		this->inicioToolStripMenuItem->Size = System::Drawing::Size(48, 20);
		this->inicioToolStripMenuItem->Text = L"Inicio";
		// 
		// buscarToolStripMenuItem
		// 
		this->buscarToolStripMenuItem->Name = L"buscarToolStripMenuItem";
		this->buscarToolStripMenuItem->Size = System::Drawing::Size(157, 22);
		this->buscarToolStripMenuItem->Text = L"Buscar";
		this->buscarToolStripMenuItem->Click += gcnew System::EventHandler(this, &VentanaOceanoP1D1::buscarToolStripMenuItem_Click);
		// 
		// modificarTextoToolStripMenuItem
		// 
		this->modificarTextoToolStripMenuItem->Name = L"modificarTextoToolStripMenuItem";
		this->modificarTextoToolStripMenuItem->Size = System::Drawing::Size(157, 22);
		this->modificarTextoToolStripMenuItem->Text = L"Modificar Texto";
		this->modificarTextoToolStripMenuItem->Click += gcnew System::EventHandler(this, &VentanaOceanoP1D1::modificarTextoToolStripMenuItem_Click);
		// 
		// dialogoAbrir
		// 
		this->dialogoAbrir->DefaultExt = L"txt";
		// 
		// dialogoGuardar
		// 
		this->dialogoGuardar->DefaultExt = L"txt";
		this->dialogoGuardar->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &VentanaOceanoP1D1::dialogoGuardar_FileOk);
		// 
		// VentanaOceanoP1D1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(625, 329);
		this->Controls->Add(this->menuStrip1);
		this->Controls->Add(this->panelBusqueda);
		this->Controls->Add(this->panelModificarTexto);
		this->MainMenuStrip = this->menuStrip1;
		this->Name = L"VentanaOceanoP1D1";
		this->Text = L"OceanoP1D1";
		this->panelBusqueda->ResumeLayout(false);
		this->panelBusqueda->PerformLayout();
		this->pUsuario->ResumeLayout(false);
		this->pUsuario->PerformLayout();
		this->panelModificarTexto->ResumeLayout(false);
		this->panelModificarTexto->PerformLayout();
		this->menuStrip1->ResumeLayout(false);
		this->menuStrip1->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

	}

	void refrecarTexto(bool limpiar);

	bool avanzarMod();
	
	string convertirSystemString(String^ pDato);

	String^ convertirStdString(string pDato);

	string intToString(int pInt);

	System::Void botonbuscar_Click(System::Object^  sender, System::EventArgs^  e);
	
	System::Void buscarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	
	System::Void modificarTextoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	System::Void bByR_Click(System::Object^  sender, System::EventArgs^  e);

	System::Void bGuardar_Click(System::Object^  sender, System::EventArgs^  e);

	System::Void tbPalabra_TextChanged(System::Object^  sender, System::EventArgs^  e);
	
	void limpiarPanelBusqueda();

	void llenarComboxSinonimos();

	int infoRepeticionPalabra();

	void resaltarTexto(int pPosicion);

	void limpiarMod();

	void cargarTextoAlLabel();

	void mensajeSesion()
	{
		MessageBoxA(NULL, "Este programa es para uso exclusivo ¡Por Favor Inicie Sesion!", "Programa Exclusivo", MB_OK);
	}
	
	System::Void bSiguiente_Click(System::Object^  sender, System::EventArgs^  e);

	System::Void bInicio_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		string codigo = convertirSystemString(tbUsuario->Text);
		System::String^ nombre = convertirStdString(_diccionario->buscarEstudiante(codigo));
		if(bInicio->Text=="Iniciar Sesion")
		{
			if (nombre!="")
			{
				
				tbUsuario->Visible=false;
				tbUsuario->Text="";
				lUsuario->Text= "Bienvenido "+ nombre;
				bInicio->Text = "Cerrar Sesion";
				login=true;
				_diccionario->setUsuario(msclr::interop::marshal_as< std::string >(nombre));
			}
		}
		else
		{
			if(bInicio->Text=="Cerrar Sesion")
			{
				
				tbUsuario->Visible=true;
				lUsuario->Text= "Usuario";
				bInicio->Text = "Iniciar Sesion";
				login=false;
			}
		}

	}
private: System::Void dialogoGuardar_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void tbUsuario_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void lUsuario_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pUsuario_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
};

