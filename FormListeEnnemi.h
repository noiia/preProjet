#pragma once

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
	public:
		FormListeEnnemi(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::ListBox^ listBox1;
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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(123, 117);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(254, 147);
			this->listBox1->TabIndex = 0;
			// 
			// FormListeEnnemi
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 353);
			this->Controls->Add(this->listBox1);
			this->Name = L"FormListeEnnemi";
			this->Text = L"FormListeEnnemi";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
