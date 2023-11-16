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
	/// Summary for FormListeEnnemi
	/// </summary>
	public ref class FormListeEnnemi : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
	public:
		FormListeEnnemi(BDD^ mabdd)
		{
			this->mabdd;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			DataGridViewTextBoxColumn^ dgvtbcName = gcnew DataGridViewTextBoxColumn();
			dgvtbcName->Name = "Name";
			this->CreatureDataGridView->Columns->Add(dgvtbcName);
			DataGridViewTextBoxColumn^ dgvtbcHp = gcnew DataGridViewTextBoxColumn();
			dgvtbcHp->Name = "HP";
			this->CreatureDataGridView->Columns->Add(dgvtbcHp);
			DataGridViewTextBoxColumn^ dgvtbcAtk = gcnew DataGridViewTextBoxColumn();
			dgvtbcAtk->Name = "Attack";
			this->CreatureDataGridView->Columns->Add(dgvtbcAtk);
			DataGridViewTextBoxColumn^ dgvtbcLvl = gcnew DataGridViewTextBoxColumn();
			dgvtbcLvl->Name = "Level";
			this->CreatureDataGridView->Columns->Add(dgvtbcLvl);
			DataGridViewTextBoxColumn^ dgvtbcID = gcnew DataGridViewTextBoxColumn();
			dgvtbcID->Name = "ID";
			this->CreatureDataGridView->Columns->Add(dgvtbcID);

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
				this->CreatureDataGridView->Rows->Add(dgvr);


			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormListeEnnemi()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ CreatureDataGridView;
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Button^ retourBtn;

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
			this->CreatureDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->retourBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreatureDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// UserDataGridView
			// 
			this->CreatureDataGridView->AllowUserToAddRows = false;
			this->CreatureDataGridView->AllowUserToDeleteRows = false;
			this->CreatureDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->CreatureDataGridView->Location = System::Drawing::Point(54, 93);
			this->CreatureDataGridView->Name = L"UserDataGridView";
			this->CreatureDataGridView->ReadOnly = true;
			this->CreatureDataGridView->Size = System::Drawing::Size(529, 303);
			this->CreatureDataGridView->TabIndex = 0;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Poor Richard", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(166, 26);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(296, 33);
			this->Title->TabIndex = 1;
			this->Title->Text = L"Liste de monstres en jeu";
			// 
			// retourBtn
			// 
			this->retourBtn->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->retourBtn->Location = System::Drawing::Point(262, 415);
			this->retourBtn->Name = L"retourBtn";
			this->retourBtn->Size = System::Drawing::Size(117, 46);
			this->retourBtn->TabIndex = 2;
			this->retourBtn->Text = L"Retour";
			this->retourBtn->UseVisualStyleBackColor = true;
			this->retourBtn->Click += gcnew System::EventHandler(this, &FormListeEnnemi::retourBtn_Click);
			// 
			// FormListeEnnemi
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(646, 484);
			this->Controls->Add(this->retourBtn);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->CreatureDataGridView);
			this->Name = L"FormListeEnnemi";
			this->Text = L"FormListeEnnemi";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CreatureDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void retourBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
