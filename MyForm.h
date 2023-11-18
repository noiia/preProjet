#pragma once

namespace preProjet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ NameText;

	protected:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ HpText;
	private: System::Windows::Forms::TextBox^ textBox2;


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->NameText = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->HpText = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(505, 365);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// NameText
			// 
			this->NameText->AutoSize = true;
			this->NameText->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameText->Location = System::Drawing::Point(12, 27);
			this->NameText->Name = L"NameText";
			this->NameText->Size = System::Drawing::Size(708, 48);
			this->NameText->TabIndex = 1;
			this->NameText->Text = L"Salut à toi, héros, bienvenu dans cette aventure, qui, je l\'espère, te sera favor"
				L"able. \nBien, dis-moi comment tu t\'appelles très cher Héro.";
			this->NameText->Click += gcnew System::EventHandler(this, &MyForm::IntroText_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(81, 120);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(250, 20);
			this->textBox1->TabIndex = 2;
			// 
			// HpText
			// 
			this->HpText->AutoSize = true;
			this->HpText->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HpText->Location = System::Drawing::Point(22, 190);
			this->HpText->Name = L"HpText";
			this->HpText->Size = System::Drawing::Size(568, 72);
			this->HpText->TabIndex = 3;
			this->HpText->Text = L"Fort bien, maintenant combien de points de vie souhaites-tu \?\nSache que plus de p"
				L"oints de vie tu as, moins de puissance tu auras.\nChoisi minutieusement ;)";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(81, 294);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(250, 20);
			this->textBox2->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(711, 511);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->HpText);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->NameText);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void IntroText_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
