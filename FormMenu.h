#pragma once

#include "FormOptions.h"

namespace preProjet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormMenu
	/// </summary>
	public ref class FormMenu : public System::Windows::Forms::Form
	{
		BDD^ bdd;
	public:
		FormMenu(BDD^ bdd)
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
		~FormMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Button^ PlayBtn;
	private: System::Windows::Forms::Button^ OptBtn;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMenu::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->PlayBtn = (gcnew System::Windows::Forms::Button());
			this->OptBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Title->Cursor = System::Windows::Forms::Cursors::Default;
			this->Title->Font = (gcnew System::Drawing::Font(L"Poor Richard", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(116, 35);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(632, 55);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Bienvenue dans Cesi et Dragons";
			// 
			// PlayBtn
			// 
			this->PlayBtn->Font = (gcnew System::Drawing::Font(L"Poor Richard", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayBtn->Location = System::Drawing::Point(204, 149);
			this->PlayBtn->Name = L"PlayBtn";
			this->PlayBtn->Size = System::Drawing::Size(212, 94);
			this->PlayBtn->TabIndex = 1;
			this->PlayBtn->Text = L"Jouer";
			this->PlayBtn->UseVisualStyleBackColor = true;
			this->PlayBtn->Click += gcnew System::EventHandler(this, &FormMenu::PlayBtn_Click);
			// 
			// OptBtn
			// 
			this->OptBtn->Font = (gcnew System::Drawing::Font(L"Poor Richard", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OptBtn->Location = System::Drawing::Point(204, 272);
			this->OptBtn->Name = L"OptBtn";
			this->OptBtn->Size = System::Drawing::Size(212, 94);
			this->OptBtn->TabIndex = 2;
			this->OptBtn->Text = L"Options";
			this->OptBtn->UseVisualStyleBackColor = true;
			this->OptBtn->Click += gcnew System::EventHandler(this, &FormMenu::OptBtn_Click);
			// 
			// FormMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(847, 464);
			this->Controls->Add(this->OptBtn);
			this->Controls->Add(this->PlayBtn);
			this->Controls->Add(this->Title);
			this->Name = L"FormMenu";
			this->Text = L"FormMenu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OptBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		FormOptions^ formOptions = gcnew FormOptions(bdd);
		formOptions->ShowDialog();
		System::Diagnostics::Debug::WriteLine("FormOptions fermé");
	}
private: System::Void PlayBtn_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
