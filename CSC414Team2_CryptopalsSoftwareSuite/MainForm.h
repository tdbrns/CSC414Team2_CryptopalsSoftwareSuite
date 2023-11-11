#pragma once

#include <msclr/marshal_cppstd.h>
#include "ChallengeSolutions.h"

using msclr::interop::marshal_as;		// marshal_as is used to convert data types defined by the .NET Framework to data types 
										// defined by the standard C++ library and vice versa.

namespace  CSC414Team2CryptopalsSoftwareSuite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:

		String^ base_hex_array;
		String^ base_64_array;
		String^ hex_1;
		String^ hex_2;
		String^ xor_results;
		String^ plain_txt;
		String^ key_txt;
		String^ cipher_txt;
		String^ single_xor_base64;
		String^ message_results;



	private: System::Windows::Forms::Button^ fixed_xor_btn;


	private: System::Windows::Forms::Button^ Convert;
	private: System::Windows::Forms::Button^ Cancel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ hex_string_1;

	private: System::Windows::Forms::TextBox^ xor_result_string;
	private: System::Windows::Forms::TextBox^ base_64;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ plain_text_box;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ cipher_text_box;
	private: System::Windows::Forms::Button^ repeat_xor_btn;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ key_text_box;
	private: System::Windows::Forms::Button^ add_file_btn;
	private: System::Windows::Forms::TextBox^ file_xor_results;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ hex_single_byte_cipher;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ message_box;
	private: System::Windows::Forms::Label^ Message;
	private: System::Windows::Forms::Button^ single_byte_xor_btn;
	private: System::Windows::Forms::TextBox^ file_break_repeat_xor_change;

	private: System::Windows::Forms::Button^ break_repeat_btn;
	private: System::Windows::Forms::Button^ AES_btn;
	private: System::Windows::Forms::TextBox^ AEX_textbox;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ Detect_AES_in_ECB_textbox;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ Detect_AES_In_ECB_btn;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ hex_string_2;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::GroupBox^ groupBox8;


	private: System::Windows::Forms::TextBox^ base_hex;

	public:
		MainForm(void)
		{
			InitializeComponent();
			base_hex_array = {};
			base_64_array = {};
			hex_1 = {};
			hex_2 = {};
			xor_results = {};
			plain_txt = {};
			key_txt = {};
			cipher_txt = {};
			single_xor_base64 = {};
			message_results = {};
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->base_64 = (gcnew System::Windows::Forms::TextBox());
			this->base_hex = (gcnew System::Windows::Forms::TextBox());
			this->hex_string_1 = (gcnew System::Windows::Forms::TextBox());
			this->xor_result_string = (gcnew System::Windows::Forms::TextBox());
			this->Convert = (gcnew System::Windows::Forms::Button());
			this->Cancel = (gcnew System::Windows::Forms::Button());
			this->fixed_xor_btn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->plain_text_box = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cipher_text_box = (gcnew System::Windows::Forms::TextBox());
			this->repeat_xor_btn = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->key_text_box = (gcnew System::Windows::Forms::TextBox());
			this->add_file_btn = (gcnew System::Windows::Forms::Button());
			this->file_xor_results = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->hex_single_byte_cipher = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->message_box = (gcnew System::Windows::Forms::TextBox());
			this->Message = (gcnew System::Windows::Forms::Label());
			this->single_byte_xor_btn = (gcnew System::Windows::Forms::Button());
			this->file_break_repeat_xor_change = (gcnew System::Windows::Forms::TextBox());
			this->break_repeat_btn = (gcnew System::Windows::Forms::Button());
			this->AES_btn = (gcnew System::Windows::Forms::Button());
			this->AEX_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Detect_AES_in_ECB_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->Detect_AES_In_ECB_btn = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->hex_string_2 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->SuspendLayout();
			// 
			// base_64
			// 
			this->base_64->Location = System::Drawing::Point(228, 20);
			this->base_64->Margin = System::Windows::Forms::Padding(4);
			this->base_64->Multiline = true;
			this->base_64->Name = L"base_64";
			this->base_64->ReadOnly = true;
			this->base_64->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->base_64->Size = System::Drawing::Size(213, 49);
			this->base_64->TabIndex = 0;
			this->base_64->WordWrap = false;
			this->base_64->TextChanged += gcnew System::EventHandler(this, &MainForm::hash_input_TextChanged);
			// 
			// base_hex
			// 
			this->base_hex->Location = System::Drawing::Point(3, 20);
			this->base_hex->Margin = System::Windows::Forms::Padding(4);
			this->base_hex->Multiline = true;
			this->base_hex->Name = L"base_hex";
			this->base_hex->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->base_hex->Size = System::Drawing::Size(217, 49);
			this->base_hex->TabIndex = 1;
			this->base_hex->WordWrap = false;
			this->base_hex->TextChanged += gcnew System::EventHandler(this, &MainForm::hash_base_hex_TextChanged);
			// 
			// hex_string_1
			// 
			this->hex_string_1->Location = System::Drawing::Point(5, 20);
			this->hex_string_1->Margin = System::Windows::Forms::Padding(4);
			this->hex_string_1->Multiline = true;
			this->hex_string_1->Name = L"hex_string_1";
			this->hex_string_1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->hex_string_1->Size = System::Drawing::Size(213, 49);
			this->hex_string_1->TabIndex = 9;
			this->hex_string_1->WordWrap = false;
			this->hex_string_1->TextChanged += gcnew System::EventHandler(this, &MainForm::xor_comparison_string_TextChanged);
			// 
			// xor_result_string
			// 
			this->xor_result_string->Location = System::Drawing::Point(447, 20);
			this->xor_result_string->Margin = System::Windows::Forms::Padding(4);
			this->xor_result_string->Multiline = true;
			this->xor_result_string->Name = L"xor_result_string";
			this->xor_result_string->ReadOnly = true;
			this->xor_result_string->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->xor_result_string->Size = System::Drawing::Size(213, 49);
			this->xor_result_string->TabIndex = 12;
			this->xor_result_string->WordWrap = false;
			this->xor_result_string->TextChanged += gcnew System::EventHandler(this, &MainForm::xor_result_string_TextChanged);
			// 
			// Convert
			// 
			this->Convert->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Convert->Location = System::Drawing::Point(3, 77);
			this->Convert->Margin = System::Windows::Forms::Padding(4);
			this->Convert->Name = L"Convert";
			this->Convert->Size = System::Drawing::Size(100, 28);
			this->Convert->TabIndex = 2;
			this->Convert->Text = L"Convert";
			this->Convert->UseVisualStyleBackColor = true;
			this->Convert->Click += gcnew System::EventHandler(this, &MainForm::hash_Click);
			// 
			// Cancel
			// 
			this->Cancel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Cancel->Location = System::Drawing::Point(0, 1258);
			this->Cancel->Margin = System::Windows::Forms::Padding(4);
			this->Cancel->Name = L"Cancel";
			this->Cancel->Size = System::Drawing::Size(894, 28);
			this->Cancel->TabIndex = 3;
			this->Cancel->Text = L"Clear All";
			this->Cancel->UseVisualStyleBackColor = true;
			this->Cancel->Click += gcnew System::EventHandler(this, &MainForm::Cancel_Click);
			// 
			// fixed_xor_btn
			// 
			this->fixed_xor_btn->Location = System::Drawing::Point(5, 80);
			this->fixed_xor_btn->Margin = System::Windows::Forms::Padding(4);
			this->fixed_xor_btn->Name = L"fixed_xor_btn";
			this->fixed_xor_btn->Size = System::Drawing::Size(120, 28);
			this->fixed_xor_btn->TabIndex = 10;
			this->fixed_xor_btn->Text = L"Fixed Xor";
			this->fixed_xor_btn->UseVisualStyleBackColor = true;
			this->fixed_xor_btn->Click += gcnew System::EventHandler(this, &MainForm::xor_combination_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(6, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Hexadecimal String";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(225, 0);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Base 64 String";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label3->Location = System::Drawing::Point(6, 0);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Hexadecimal String 1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(444, 0);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Xor Result";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(4, 0);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 16);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Plain Text";
			// 
			// plain_text_box
			// 
			this->plain_text_box->Location = System::Drawing::Point(7, 20);
			this->plain_text_box->Margin = System::Windows::Forms::Padding(4);
			this->plain_text_box->Multiline = true;
			this->plain_text_box->Name = L"plain_text_box";
			this->plain_text_box->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->plain_text_box->Size = System::Drawing::Size(300, 83);
			this->plain_text_box->TabIndex = 14;
			this->plain_text_box->WordWrap = false;
			this->plain_text_box->TextChanged += gcnew System::EventHandler(this, &MainForm::plain_text_box_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(527, 4);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 16);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Cipher Text";
			// 
			// cipher_text_box
			// 
			this->cipher_text_box->Location = System::Drawing::Point(527, 24);
			this->cipher_text_box->Margin = System::Windows::Forms::Padding(4);
			this->cipher_text_box->Multiline = true;
			this->cipher_text_box->Name = L"cipher_text_box";
			this->cipher_text_box->ReadOnly = true;
			this->cipher_text_box->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->cipher_text_box->Size = System::Drawing::Size(306, 83);
			this->cipher_text_box->TabIndex = 16;
			this->cipher_text_box->WordWrap = false;
			this->cipher_text_box->TextChanged += gcnew System::EventHandler(this, &MainForm::cipher_text_box_TextChanged);
			// 
			// repeat_xor_btn
			// 
			this->repeat_xor_btn->Location = System::Drawing::Point(7, 111);
			this->repeat_xor_btn->Margin = System::Windows::Forms::Padding(4);
			this->repeat_xor_btn->Name = L"repeat_xor_btn";
			this->repeat_xor_btn->Size = System::Drawing::Size(100, 28);
			this->repeat_xor_btn->TabIndex = 17;
			this->repeat_xor_btn->Text = L"Repeat Xor";
			this->repeat_xor_btn->UseVisualStyleBackColor = true;
			this->repeat_xor_btn->Click += gcnew System::EventHandler(this, &MainForm::repeat_xor_btn_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(318, 1);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 16);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Key";
			// 
			// key_text_box
			// 
			this->key_text_box->Location = System::Drawing::Point(315, 20);
			this->key_text_box->Margin = System::Windows::Forms::Padding(4);
			this->key_text_box->Multiline = true;
			this->key_text_box->Name = L"key_text_box";
			this->key_text_box->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->key_text_box->Size = System::Drawing::Size(204, 50);
			this->key_text_box->TabIndex = 19;
			this->key_text_box->WordWrap = false;
			this->key_text_box->TextChanged += gcnew System::EventHandler(this, &MainForm::key_text_box_TextChanged);
			// 
			// add_file_btn
			// 
			this->add_file_btn->Location = System::Drawing::Point(3, 111);
			this->add_file_btn->Margin = System::Windows::Forms::Padding(4);
			this->add_file_btn->Name = L"add_file_btn";
			this->add_file_btn->Size = System::Drawing::Size(100, 28);
			this->add_file_btn->TabIndex = 20;
			this->add_file_btn->Text = L"Choose File";
			this->add_file_btn->UseVisualStyleBackColor = true;
			this->add_file_btn->Click += gcnew System::EventHandler(this, &MainForm::add_file_btn_Click);
			// 
			// file_xor_results
			// 
			this->file_xor_results->Location = System::Drawing::Point(4, 20);
			this->file_xor_results->Margin = System::Windows::Forms::Padding(4);
			this->file_xor_results->Multiline = true;
			this->file_xor_results->Name = L"file_xor_results";
			this->file_xor_results->ReadOnly = true;
			this->file_xor_results->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->file_xor_results->Size = System::Drawing::Size(304, 83);
			this->file_xor_results->TabIndex = 21;
			this->file_xor_results->WordWrap = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 7);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(260, 16);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Break Repeat Key Xor (Key and Message)";
			// 
			// hex_single_byte_cipher
			// 
			this->hex_single_byte_cipher->Location = System::Drawing::Point(3, 20);
			this->hex_single_byte_cipher->Margin = System::Windows::Forms::Padding(4);
			this->hex_single_byte_cipher->Multiline = true;
			this->hex_single_byte_cipher->Name = L"hex_single_byte_cipher";
			this->hex_single_byte_cipher->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->hex_single_byte_cipher->Size = System::Drawing::Size(213, 49);
			this->hex_single_byte_cipher->TabIndex = 23;
			this->hex_single_byte_cipher->WordWrap = false;
			this->hex_single_byte_cipher->TextChanged += gcnew System::EventHandler(this, &MainForm::hex_single_byte_cipher_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 0);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(124, 16);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Hexadecimal String";
			// 
			// message_box
			// 
			this->message_box->Location = System::Drawing::Point(224, 20);
			this->message_box->Margin = System::Windows::Forms::Padding(4);
			this->message_box->Multiline = true;
			this->message_box->Name = L"message_box";
			this->message_box->ReadOnly = true;
			this->message_box->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->message_box->Size = System::Drawing::Size(335, 85);
			this->message_box->TabIndex = 25;
			this->message_box->WordWrap = false;
			this->message_box->TextChanged += gcnew System::EventHandler(this, &MainForm::message_box_TextChanged);
			// 
			// Message
			// 
			this->Message->AutoSize = true;
			this->Message->Location = System::Drawing::Point(221, 0);
			this->Message->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Message->Name = L"Message";
			this->Message->Size = System::Drawing::Size(116, 16);
			this->Message->TabIndex = 26;
			this->Message->Text = L"Key and Message";
			// 
			// single_byte_xor_btn
			// 
			this->single_byte_xor_btn->Location = System::Drawing::Point(3, 77);
			this->single_byte_xor_btn->Margin = System::Windows::Forms::Padding(4);
			this->single_byte_xor_btn->Name = L"single_byte_xor_btn";
			this->single_byte_xor_btn->Size = System::Drawing::Size(120, 28);
			this->single_byte_xor_btn->TabIndex = 27;
			this->single_byte_xor_btn->Text = L"Single Byte Xor";
			this->single_byte_xor_btn->UseVisualStyleBackColor = true;
			this->single_byte_xor_btn->Click += gcnew System::EventHandler(this, &MainForm::single_byte_xor_btn_Click);
			// 
			// file_break_repeat_xor_change
			// 
			this->file_break_repeat_xor_change->Location = System::Drawing::Point(5, 27);
			this->file_break_repeat_xor_change->Margin = System::Windows::Forms::Padding(4);
			this->file_break_repeat_xor_change->Multiline = true;
			this->file_break_repeat_xor_change->Name = L"file_break_repeat_xor_change";
			this->file_break_repeat_xor_change->ReadOnly = true;
			this->file_break_repeat_xor_change->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->file_break_repeat_xor_change->Size = System::Drawing::Size(308, 83);
			this->file_break_repeat_xor_change->TabIndex = 28;
			this->file_break_repeat_xor_change->WordWrap = false;
			// 
			// break_repeat_btn
			// 
			this->break_repeat_btn->Location = System::Drawing::Point(5, 118);
			this->break_repeat_btn->Margin = System::Windows::Forms::Padding(4);
			this->break_repeat_btn->Name = L"break_repeat_btn";
			this->break_repeat_btn->Size = System::Drawing::Size(100, 28);
			this->break_repeat_btn->TabIndex = 29;
			this->break_repeat_btn->Text = L"Choose File";
			this->break_repeat_btn->UseVisualStyleBackColor = true;
			this->break_repeat_btn->Click += gcnew System::EventHandler(this, &MainForm::break_repeat_btn_Click);
			// 
			// AES_btn
			// 
			this->AES_btn->Location = System::Drawing::Point(3, 127);
			this->AES_btn->Margin = System::Windows::Forms::Padding(4);
			this->AES_btn->Name = L"AES_btn";
			this->AES_btn->Size = System::Drawing::Size(100, 28);
			this->AES_btn->TabIndex = 30;
			this->AES_btn->Text = L"Choose File";
			this->AES_btn->UseVisualStyleBackColor = true;
			this->AES_btn->Click += gcnew System::EventHandler(this, &MainForm::AES_btn_Click);
			// 
			// AEX_textbox
			// 
			this->AEX_textbox->Location = System::Drawing::Point(5, 36);
			this->AEX_textbox->Margin = System::Windows::Forms::Padding(4);
			this->AEX_textbox->Multiline = true;
			this->AEX_textbox->Name = L"AEX_textbox";
			this->AEX_textbox->ReadOnly = true;
			this->AEX_textbox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->AEX_textbox->Size = System::Drawing::Size(308, 83);
			this->AEX_textbox->TabIndex = 31;
			this->AEX_textbox->WordWrap = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 16);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(235, 16);
			this->label10->TabIndex = 32;
			this->label10->Text = L"AES in ECB Mode (Key and Message)";
			// 
			// Detect_AES_in_ECB_textbox
			// 
			this->Detect_AES_in_ECB_textbox->Location = System::Drawing::Point(4, 20);
			this->Detect_AES_in_ECB_textbox->Margin = System::Windows::Forms::Padding(4);
			this->Detect_AES_in_ECB_textbox->Multiline = true;
			this->Detect_AES_in_ECB_textbox->Name = L"Detect_AES_in_ECB_textbox";
			this->Detect_AES_in_ECB_textbox->ReadOnly = true;
			this->Detect_AES_in_ECB_textbox->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->Detect_AES_in_ECB_textbox->Size = System::Drawing::Size(307, 83);
			this->Detect_AES_in_ECB_textbox->TabIndex = 33;
			this->Detect_AES_in_ECB_textbox->WordWrap = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(4, 0);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(157, 16);
			this->label11->TabIndex = 34;
			this->label11->Text = L"Detect AES In ECB Mode";
			// 
			// Detect_AES_In_ECB_btn
			// 
			this->Detect_AES_In_ECB_btn->Location = System::Drawing::Point(4, 111);
			this->Detect_AES_In_ECB_btn->Margin = System::Windows::Forms::Padding(4);
			this->Detect_AES_In_ECB_btn->Name = L"Detect_AES_In_ECB_btn";
			this->Detect_AES_In_ECB_btn->Size = System::Drawing::Size(100, 28);
			this->Detect_AES_In_ECB_btn->TabIndex = 35;
			this->Detect_AES_In_ECB_btn->Text = L"Choose File";
			this->Detect_AES_In_ECB_btn->UseVisualStyleBackColor = true;
			this->Detect_AES_In_ECB_btn->Click += gcnew System::EventHandler(this, &MainForm::Detect_AES_In_ECB_btn_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(8, 0);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(141, 16);
			this->label12->TabIndex = 36;
			this->label12->Text = L"Detect Single Char Xor";
			// 
			// hex_string_2
			// 
			this->hex_string_2->Location = System::Drawing::Point(226, 20);
			this->hex_string_2->Margin = System::Windows::Forms::Padding(4);
			this->hex_string_2->Multiline = true;
			this->hex_string_2->Name = L"hex_string_2";
			this->hex_string_2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->hex_string_2->Size = System::Drawing::Size(213, 49);
			this->hex_string_2->TabIndex = 37;
			this->hex_string_2->WordWrap = false;
			this->hex_string_2->TextChanged += gcnew System::EventHandler(this, &MainForm::hex_string_2_TextChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(225, 0);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(134, 16);
			this->label13->TabIndex = 38;
			this->label13->Text = L"Hexadecimal String 2";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->base_hex);
			this->groupBox1->Controls->Add(this->base_64);
			this->groupBox1->Controls->Add(this->Convert);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(450, 110);
			this->groupBox1->TabIndex = 39;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->hex_string_2);
			this->groupBox2->Controls->Add(this->xor_result_string);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->fixed_xor_btn);
			this->groupBox2->Controls->Add(this->hex_string_1);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Location = System::Drawing::Point(10, 141);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(669, 111);
			this->groupBox2->TabIndex = 40;
			this->groupBox2->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->groupBox3->Controls->Add(this->single_byte_xor_btn);
			this->groupBox3->Controls->Add(this->Message);
			this->groupBox3->Controls->Add(this->message_box);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->hex_single_byte_cipher);
			this->groupBox3->Location = System::Drawing::Point(10, 271);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(570, 119);
			this->groupBox3->TabIndex = 41;
			this->groupBox3->TabStop = false;
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->groupBox4->Controls->Add(this->label12);
			this->groupBox4->Controls->Add(this->file_xor_results);
			this->groupBox4->Controls->Add(this->add_file_btn);
			this->groupBox4->Location = System::Drawing::Point(11, 413);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(316, 144);
			this->groupBox4->TabIndex = 42;
			this->groupBox4->TabStop = false;
			// 
			// groupBox5
			// 
			this->groupBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->groupBox5->Controls->Add(this->cipher_text_box);
			this->groupBox5->Controls->Add(this->plain_text_box);
			this->groupBox5->Controls->Add(this->key_text_box);
			this->groupBox5->Controls->Add(this->label7);
			this->groupBox5->Controls->Add(this->repeat_xor_btn);
			this->groupBox5->Controls->Add(this->label6);
			this->groupBox5->Controls->Add(this->label5);
			this->groupBox5->Location = System::Drawing::Point(11, 581);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(842, 147);
			this->groupBox5->TabIndex = 0;
			this->groupBox5->TabStop = false;
			// 
			// groupBox6
			// 
			this->groupBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->groupBox6->Controls->Add(this->break_repeat_btn);
			this->groupBox6->Controls->Add(this->file_break_repeat_xor_change);
			this->groupBox6->Controls->Add(this->label8);
			this->groupBox6->Location = System::Drawing::Point(8, 753);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(322, 153);
			this->groupBox6->TabIndex = 43;
			this->groupBox6->TabStop = false;
			// 
			// groupBox7
			// 
			this->groupBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->groupBox7->Controls->Add(this->AEX_textbox);
			this->groupBox7->Controls->Add(this->label10);
			this->groupBox7->Controls->Add(this->AES_btn);
			this->groupBox7->Location = System::Drawing::Point(8, 928);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(322, 165);
			this->groupBox7->TabIndex = 44;
			this->groupBox7->TabStop = false;
			// 
			// groupBox8
			// 
			this->groupBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->groupBox8->Controls->Add(this->Detect_AES_in_ECB_textbox);
			this->groupBox8->Controls->Add(this->Detect_AES_In_ECB_btn);
			this->groupBox8->Controls->Add(this->label11);
			this->groupBox8->Location = System::Drawing::Point(8, 1113);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(320, 145);
			this->groupBox8->TabIndex = 45;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"groupBox8";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(915, 753);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Cancel);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"CryptoPal";
			this->Load += gcnew System::EventHandler(this, &MainForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void hash_base_hex_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ inputText = base_hex->Text;
		base_hex_array = inputText;
	}

	private: System::Void hash_input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ outputText = base_64_array;
	}

	private: System::Void xor_comparison_string_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ inputText = hex_string_1->Text;
		hex_1 = inputText;
	}

	private: System::Void hex_string_2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ inputText = hex_string_2->Text;
		hex_2 = inputText;
	}

	private: System::Void xor_result_string_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ output_text = xor_results;
	}

	private: System::Void hex_single_byte_cipher_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ inputText = hex_single_byte_cipher->Text;
		single_xor_base64 = inputText;
	}

	private: System::Void message_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ output_text = message_results;
	}

	private: System::Void key_text_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ inputText = key_text_box->Text;
		key_txt = inputText;
	}

	private: System::Void plain_text_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ inputText = plain_text_box->Text;
		plain_txt = inputText;
	}

	private: System::Void cipher_text_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ outputText = cipher_txt;
	}

	private: System::Void hash_Click(System::Object^ sender, System::EventArgs^ e)
	{
		base_hex_array = base_hex->Text;
		hex_to_base64();
	}

	private: System::Void xor_combination_Click(System::Object^ sender, System::EventArgs^ e)
	{
		base_hex_array = base_hex->Text;
		fixed_xor();
	}

	private: System::Void repeat_xor_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{

		repeat_xor();
	}

	private: System::Void single_byte_xor_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		single_byte_cipher();
	}

	private: System::Void add_file_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		single_char_xor();
	};

	private: System::Void break_repeat_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		break_repeat_key_xor();
	}

	private: System::Void AES_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		AES_in_ECB();
	}

	private: System::Void Detect_AES_In_ECB_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Detect_AES_in_ECB();
	}

	private: System::Void Cancel_Click(System::Object^ sender, System::EventArgs^ e)
	{
		base_hex->Text = "";
		base_64->Text = "";
		hex_string_1->Text = "";
		hex_string_2->Text = "";
		xor_result_string->Text = "";
		hex_single_byte_cipher->Text = "";
		message_box->Text = "";
		file_xor_results->Text = "";
		file_break_repeat_xor_change->Text = "";
		AEX_textbox->Text = "";
		Detect_AES_in_ECB_textbox->Text = "";
		key_text_box->Text = "";
		plain_text_box->Text = "";
		cipher_text_box->Text = "";
	}

		   /*************************************************** UI Method for Challenge 1 ***************************************************/
		   void MainForm::hex_to_base64()
		   {
			   ChallengeSolution solution;
			   String^ managedString = base_hex_array;

			   // Check if base_hex_array is not empty
			   if (!String::IsNullOrEmpty(base_hex_array)) 
			   {
					string hexString = marshal_as<string>(managedString);
					string base64_string = solution.HexToBase64(hexString);

					base_64->Text = gcnew String(base64_string.c_str());
			   }
			   else
					base_64->Text = "Input is empty.";
		   }

		   /*************************************************** UI Method for Challenge 2 ***************************************************/
		   void MainForm::fixed_xor()
		   {
			   ChallengeSolution solution;
			   String^ managedString = hex_1;
			   String^ managedString_2 = hex_2;
			   string hexString = marshal_as<string>(managedString);

			   if (!String::IsNullOrEmpty(hex_1))
			   {
				   string xor_string = marshal_as<string>(managedString);
				   string xor_string_2 = marshal_as<string>(managedString_2);
				   string result_xor = solution.FixedXOR(xor_string, xor_string_2);
				   xor_result_string->Text = gcnew String(result_xor.c_str());
			   }
			   else
				   xor_result_string->Text = "Input is empty.";
		   }

		   /*************************************************** UI Method for Challenge 3 ***************************************************/
		   void MainForm::single_byte_cipher()
		   {
			   ChallengeSolution solution;
			   String^ managedString = single_xor_base64;
			   String^ managedString2 = message_results;

			   if (!String::IsNullOrEmpty(single_xor_base64)) 
			   {
				   string single_xor_base64_txt = marshal_as<string>(managedString);
				   string message = solution.SingleByteXORCipher(single_xor_base64_txt);
				   message_box->Text = gcnew String(message.c_str());
			   }
			   else 
				   message_box->Text = "Input is empty.";
		   }

		   /*************************************************** UI Method for Challenge 4 ***************************************************/
		   void MainForm::single_char_xor()
		   {
			   ChallengeSolution solution;
			   OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

			   // Set the file filter and other properties
			   openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			   openFileDialog1->FilterIndex = 1;
			   openFileDialog1->RestoreDirectory = true;

			   if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
			   {   
				   string filePathStr = marshal_as<string>(openFileDialog1->FileName);
				   string result = solution.DetectSingleCharXOR(filePathStr);

				   file_xor_results->Text = gcnew String(result.c_str());
			   }
			   else
				   Detect_AES_in_ECB_textbox->Text = "Cannot open dialog box";
		   }

		   /*************************************************** UI Method for Challenge 5 ***************************************************/
		   void MainForm::repeat_xor()
		   {
			   ChallengeSolution solution;
			   String^ managedString = plain_txt;
			   String^ managedString_2 = key_txt;
			   string plain_txt_string = marshal_as<string>(managedString);

			   if (!String::IsNullOrEmpty(key_txt)) 
			   {
				   string key_txt_string = marshal_as<string>(managedString_2);
				   string cipher_result = solution.RepeatingKeyXOR(plain_txt_string, key_txt_string);
				   cipher_text_box->Text = gcnew String(cipher_result.c_str());
			   }
			   else
				   cipher_text_box->Text = "Input is empty.";
		   }

		   /*************************************************** UI Method for Challenge 6 ***************************************************/
		   void MainForm::break_repeat_key_xor()
		   {
			   ChallengeSolution solution;
			   OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

			   openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			   openFileDialog1->FilterIndex = 1;
			   openFileDialog1->RestoreDirectory = true;

			   if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
			   {
				   string filePathStr = marshal_as<string>(openFileDialog1->FileName);
				   string result = solution.BreakRepeatingKeyXOR(filePathStr);

				   file_break_repeat_xor_change->Text = gcnew String(result.c_str());
			   }
			   else
				   Detect_AES_in_ECB_textbox->Text = "Cannot open dialog box";
		   }

		   /*************************************************** UI Method for Challenge 7 ***************************************************/
		   void MainForm::AES_in_ECB()
		   {
			   ChallengeSolution solution;
			   OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

			   // Set the file filter and other properties as needed.
			   openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			   openFileDialog1->FilterIndex = 1;
			   openFileDialog1->RestoreDirectory = true;
			   
			   if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
			   {
				   string filePathStr = marshal_as<string>(openFileDialog1->FileName);
				   string result = solution.AES_ECBMode(filePathStr);

				   AEX_textbox->Text = gcnew String(result.c_str());
			   }
			   else
				   Detect_AES_in_ECB_textbox->Text = "Cannot open dialog box";
		   }

		   /*************************************************** UI Method for Challenge 8 ***************************************************/
		   void MainForm::Detect_AES_in_ECB()
		   {
			   ChallengeSolution solution;
			   OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

			   // Set the file filter and other properties as needed.
			   openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
			   openFileDialog1->FilterIndex = 1;
			   openFileDialog1->RestoreDirectory = true;

			   if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			   {
				   // Convert the selectedFileName to a standard string (if needed).
				   string filePathStr = marshal_as<string>(openFileDialog1->FileName);

				   // Call the DetectSingleCharXOR function with the selected file name.
				   string result = solution.DetectAES_ECBMode(filePathStr);

				   Detect_AES_in_ECB_textbox->Text = gcnew String(result.c_str());
			   }
			   else
				   Detect_AES_in_ECB_textbox->Text = "Cannot open dialog box";
		   }
	};
}