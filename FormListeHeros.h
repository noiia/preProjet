#pragma once
#include "BDD.h"

namespace preProjet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormListeHeros
	/// </summary>
	public ref class FormListeHeros : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		FormListeHeros(BDD^ mabdd)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->mabdd = mabdd;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			DataGridViewTextBoxColumn^ dgvtbcName = gcnew DataGridViewTextBoxColumn();
			dgvtbcName->Name = "Name";
			this->HeroDataGridView->Columns->Add(dgvtbcName);
			DataGridViewTextBoxColumn^ dgvtbcHp = gcnew DataGridViewTextBoxColumn();
			dgvtbcHp->Name = "HP";
			this->HeroDataGridView->Columns->Add(dgvtbcHp);
			DataGridViewTextBoxColumn^ dgvtbcAtk = gcnew DataGridViewTextBoxColumn();
			dgvtbcAtk->Name = "Attack";
			this->HeroDataGridView->Columns->Add(dgvtbcAtk);
			DataGridViewTextBoxColumn^ dgvtbcLvl = gcnew DataGridViewTextBoxColumn();
			dgvtbcLvl->Name = "Level";
			this->HeroDataGridView->Columns->Add(dgvtbcLvl);
			DataGridViewTextBoxColumn^ dgvtbcLvlStat = gcnew DataGridViewTextBoxColumn();
			dgvtbcLvlStat->Name = "Level status";
			this->HeroDataGridView->Columns->Add(dgvtbcLvlStat);
			DataGridViewTextBoxColumn^ dgvtbcID = gcnew DataGridViewTextBoxColumn();
			dgvtbcID->Name = "ID";
			this->HeroDataGridView->Columns->Add(dgvtbcID);

			DataSet^ ds = mabdd->executeQuery("SELECT * FROM utilisateur");

			for each (DataRow ^ row in ds->Tables[0]->Rows)
			{

				int id = (int)row[0];
				System::Diagnostics::Debug::WriteLine("id " + id);
				String^ nom = (String^)row[1];
				System::Diagnostics::Debug::WriteLine("nom " + nom);

				DataGridViewRow^ dgvr = gcnew DataGridViewRow();
				DataGridViewTextBoxCell^ dgvc = gcnew DataGridViewTextBoxCell();
				dgvc->Value = Convert::ToString(id);
				dgvr->Cells->Add(dgvc);
				DataGridViewTextBoxCell^ dgvc2 = gcnew DataGridViewTextBoxCell();
				dgvc2->Value = nom;
				dgvr->Cells->Add(dgvc2);
				this->HeroDataGridView->Rows->Add(dgvr);


			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormListeHeros()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ retourBtn;
	protected:
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::DataGridView^ HeroDataGridView;


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
			this->retourBtn = (gcnew System::Windows::Forms::Button());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->HeroDataGridView = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HeroDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// retourBtn
			// 
			this->retourBtn->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->retourBtn->Location = System::Drawing::Point(238, 398);
			this->retourBtn->Name = L"retourBtn";
			this->retourBtn->Size = System::Drawing::Size(117, 46);
			this->retourBtn->TabIndex = 5;
			this->retourBtn->Text = L"Retour";
			this->retourBtn->UseVisualStyleBackColor = true;
			this->retourBtn->Click += gcnew System::EventHandler(this, &FormListeHeros::retourBtn_Click);
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(142, 9);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(296, 33);
			this->Title->TabIndex = 4;
			this->Title->Text = L"Liste de monstres en jeu";
			// 
			// HeroDataGridView
			// 
			this->HeroDataGridView->AllowUserToAddRows = false;
			this->HeroDataGridView->AllowUserToDeleteRows = false;
			this->HeroDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->HeroDataGridView->Location = System::Drawing::Point(30, 76);
			this->HeroDataGridView->Name = L"HeroDataGridView";
			this->HeroDataGridView->ReadOnly = true;
			this->HeroDataGridView->Size = System::Drawing::Size(529, 303);
			this->HeroDataGridView->TabIndex = 3;
			// 
			// FormListeHeros
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(597, 480);
			this->Controls->Add(this->retourBtn);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->HeroDataGridView);
			this->Name = L"FormListeHeros";
			this->Text = L"FormListeHeros";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HeroDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void retourBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
