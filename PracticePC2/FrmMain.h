#pragma once
#include "Heroe.h"
namespace PracticePC2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	public:
		FrmMain(void)
		{
			InitializeComponent();
			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);


			bmpHeroe = gcnew Bitmap("heroe1.png");

			heroe = new Heroe(bmpHeroe->Width / 4, bmpHeroe->Height / 4);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Panel^ pnlCanvas;


	private:
		// ** buffer elements **
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpHeroe;

		Heroe* heroe;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMain::timer1_Tick);
			// 
			// pnlCanvas
			// 
			this->pnlCanvas->Location = System::Drawing::Point(0, 0);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(1302, 687);
			this->pnlCanvas->TabIndex = 0;
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1302, 685);
			this->Controls->Add(this->pnlCanvas);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->Load += gcnew System::EventHandler(this, &FrmMain::FrmMain_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmMain_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//clear
		//collision
		//move
		//draw
		heroe->dibujar(buffer->Graphics, bmpHeroe);
		//render
		buffer->Render(g);
	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
	};
}
