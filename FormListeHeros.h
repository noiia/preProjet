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
		BDD^ bdd;
	public:
		FormListeHeros(BDD^ bdd)
		{
			this->bdd = bdd;
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

			DataSet^ ds = bdd->executeQuery("SELECT * FROM Heros");

			for each (DataRow ^ row in ds->Tables[0]->Rows)
			{

				String^ Name = (String^)row[0];
				//System::Diagnostics::Debug::WriteLine("Nom " + Name);
				int Hp = (int)row[1];
				//System::Diagnostics::Debug::WriteLine("Pv " + Hp);
				int Atk = (int)row[2];
				//System::Diagnostics::Debug::WriteLine("Atk " + Atk);
				int Lv = (int)row[3];
				//System::Diagnostics::Debug::WriteLine("Lv " + Lv);
				int LvStat = (int)row[4];
				//System::Diagnostics::Debug::WriteLine("Lv " + LvStat);
				int ID = (int)row[5];
				//System::Diagnostics::Debug::WriteLine("ID " + ID);

				DataGridViewRow^ dgvr = gcnew DataGridViewRow();
				DataGridViewTextBoxCell^ dgvtbcName = gcnew DataGridViewTextBoxCell();
				dgvtbcName->Value = Name;
				dgvr->Cells->Add(dgvtbcName);

				DataGridViewTextBoxCell^ dgvtbcHp = gcnew DataGridViewTextBoxCell();
				dgvtbcHp->Value = Hp;
				dgvr->Cells->Add(dgvtbcHp);

				DataGridViewTextBoxCell^ dgvtbcAtk = gcnew DataGridViewTextBoxCell();
				dgvtbcAtk->Value = Atk;
				dgvr->Cells->Add(dgvtbcAtk);

				DataGridViewTextBoxCell^ dgvtbcLv = gcnew DataGridViewTextBoxCell();
				dgvtbcLv->Value = Lv;
				dgvr->Cells->Add(dgvtbcLv);

				DataGridViewTextBoxCell^ dgvtbcLvStat = gcnew DataGridViewTextBoxCell();
				dgvtbcLvStat->Value = LvStat;
				dgvr->Cells->Add(dgvtbcLvStat);

				DataGridViewTextBoxCell^ dgvtbcID = gcnew DataGridViewTextBoxCell();
				dgvtbcID->Value = ID;
				dgvr->Cells->Add(dgvtbcID);

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
			this->retourBtn->Location = System::Drawing::Point(336, 453);
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
			this->Title->Location = System::Drawing::Point(262, 25);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(261, 33);
			this->Title->TabIndex = 4;
			this->Title->Text = L"Liste de Héros en jeu";
			this->Title->Click += gcnew System::EventHandler(this, &FormListeHeros::Title_Click);
			// 
			// HeroDataGridView
			// 
			this->HeroDataGridView->AllowUserToAddRows = false;
			this->HeroDataGridView->AllowUserToDeleteRows = false;
			this->HeroDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->HeroDataGridView->Location = System::Drawing::Point(30, 76);
			this->HeroDataGridView->Name = L"HeroDataGridView";
			this->HeroDataGridView->ReadOnly = true;
			this->HeroDataGridView->Size = System::Drawing::Size(729, 361);
			this->HeroDataGridView->TabIndex = 3;
			this->HeroDataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormListeHeros::HeroDataGridView_CellContentClick);
			// 
			// FormListeHeros
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(791, 532);
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
	private: System::Void Title_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void HeroDataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
