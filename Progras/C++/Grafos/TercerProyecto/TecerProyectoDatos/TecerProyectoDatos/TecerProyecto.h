#pragma once

#include "GrafoContinental.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Resumen de TecerProyecto
/// </summary>
public ref class TecerProyecto : public System::Windows::Forms::Form
{
public:
	TecerProyecto(void)
	{
		InitializeComponent();
	
		continente = gcnew GrafoContinental(panel1);
		//
		//TODO: agregar código de constructor aquí
		//
	}

protected:
	/// <summary>
	/// Limpiar los recursos que se estén utilizando.
	/// </summary>
	~TecerProyecto()
	{
		if (components)
		{
			delete components;
		}
	}
private:
	
	GrafoContinental^ continente;

	System::Windows::Forms::Button^  button1;
	System::Windows::Forms::Button^  button2;
	System::Windows::Forms::Button^  button3;
	System::Windows::Forms::RichTextBox^  consola;
	System::Windows::Forms::Panel^  panel1;




protected:

private:
	/// <summary>
	/// Variable del diseñador requerida.
	/// </summary>
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Método necesario para admitir el Diseñador. No se puede modificar
	/// el contenido del método con el editor de código.
	/// </summary>
	void InitializeComponent(void)
	{
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TecerProyecto::typeid));
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->consola = (gcnew System::Windows::Forms::RichTextBox());
		this->panel1 = (gcnew System::Windows::Forms::Panel());
		this->panel1->SuspendLayout();
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(690, 19);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(82, 26);
		this->button1->TabIndex = 0;
		this->button1->Text = L"MostrarMapa";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &TecerProyecto::button1_Click);
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(809, 22);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(81, 23);
		this->button2->TabIndex = 1;
		this->button2->Text = L"PintarMapa";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &TecerProyecto::button2_Click);
		// 
		// button3
		// 
		this->button3->Location = System::Drawing::Point(753, 67);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(76, 23);
		this->button3->TabIndex = 2;
		this->button3->Text = L"Prueba";
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &TecerProyecto::button3_Click);
		// 
		// consola
		// 
		this->consola->Location = System::Drawing::Point(680, 147);
		this->consola->Name = L"consola";
		this->consola->Size = System::Drawing::Size(309, 96);
		this->consola->TabIndex = 3;
		this->consola->Text = L"";
		// 
		// panel1
		// 
		this->panel1->Controls->Add(this->consola);
		this->panel1->Controls->Add(this->button3);
		this->panel1->Controls->Add(this->button2);
		this->panel1->Controls->Add(this->button1);
		this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
		this->panel1->Location = System::Drawing::Point(0, 0);
		this->panel1->Name = L"panel1";
		this->panel1->Size = System::Drawing::Size(1022, 561);
		this->panel1->TabIndex = 4;
		this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &TecerProyecto::MouseMove);

		// 
		// TecerProyecto
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(1022, 561);
		this->Controls->Add(this->panel1);
		this->Name = L"TecerProyecto";
		this->Text = L"TecerProyecto";
		this->panel1->ResumeLayout(false);
		this->panel1->PerformLayout();
		this->ResumeLayout(false);

	}
#pragma endregion

private: 
	System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void MouseMove(Object^, System::Windows::Forms::MouseEventArgs^ e)
	{
		System::String^ mouseX = System::Convert::ToString(e->X);
		System::String^ mouseY = System::Convert::ToString(e->Y);
		consola->Text = mouseX + "," + mouseY;
	}
};
