#pragma once
#include "FormListeHeros.h"
#include "FormListeEnnemi.h"
#include "BDD.h"

namespace preProjet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormOptions
	/// </summary>
	public ref class FormOptions : public System::Windows::Forms::Form
	{
		BDD^ bdd;//jamais initialisé ?
	public:
		FormOptions(BDD^ bdd)
		{
			this->bdd = bdd;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormOptions()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Button^ HeroBtn;
	private: System::Windows::Forms::Button^ EnnemiBtn;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormOptions::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->HeroBtn = (gcnew System::Windows::Forms::Button());
			this->EnnemiBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Poor Richard", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(288, 40);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(136, 44);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Options";
			// 
			// HeroBtn
			// 
			this->HeroBtn->Font = (gcnew System::Drawing::Font(L"Poor Richard", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HeroBtn->Location = System::Drawing::Point(279, 164);
			this->HeroBtn->Name = L"HeroBtn";
			this->HeroBtn->Size = System::Drawing::Size(158, 64);
			this->HeroBtn->TabIndex = 1;
			this->HeroBtn->Text = L"Héros";
			this->HeroBtn->UseVisualStyleBackColor = true;
			this->HeroBtn->Click += gcnew System::EventHandler(this, &FormOptions::HeroBtn_Click);
			// 
			// EnnemiBtn
			// 
			this->EnnemiBtn->Font = (gcnew System::Drawing::Font(L"Poor Richard", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnnemiBtn->Location = System::Drawing::Point(279, 269);
			this->EnnemiBtn->Name = L"EnnemiBtn";
			this->EnnemiBtn->Size = System::Drawing::Size(158, 64);
			this->EnnemiBtn->TabIndex = 2;
			this->EnnemiBtn->Text = L"Liste d\'ennemis";
			this->EnnemiBtn->UseVisualStyleBackColor = true;
			this->EnnemiBtn->Click += gcnew System::EventHandler(this, &FormOptions::EnnemiBtn_Click);
			// 
			// FormOptions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(727, 458);
			this->Controls->Add(this->EnnemiBtn);
			this->Controls->Add(this->HeroBtn);
			this->Controls->Add(this->Title);
			this->Name = L"FormOptions";
			this->Text = L"FormOptions";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void EnnemiBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		FormListeEnnemi^ formListeEnnemi = gcnew FormListeEnnemi(bdd);
		formListeEnnemi->ShowDialog();
		System::Diagnostics::Debug::WriteLine("FormListeEnnemi fermé");
		}
	private: System::Void HeroBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		FormListeHeros^ formListeHeros = gcnew FormListeHeros(bdd);
		formListeHeros->ShowDialog();
		System::Diagnostics::Debug::WriteLine("FormListeHero fermé");
	}
};
}