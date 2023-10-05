#pragma once

#include <msclr/marshal_cppstd.h>
#include "ChallengeSolutions.h"
#include <fstream>



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
        String^ xor_compare;
        String^ xor_results;
        String^ plain_txt;
        String^ key_txt;
        String^ cipher_txt;
        String^ single_xor_base64;
        String^ message_results;

    private: System::Windows::Forms::PictureBox^ background_img;

    private: System::Windows::Forms::Button^ fixed_xor_btn;


    private: System::Windows::Forms::Button^ Convert;
    private: System::Windows::Forms::Button^ Cancel;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ xor_comparison_string;
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










    private: System::Windows::Forms::TextBox^ base_hex;


        //private: System::Windows::Forms::TextBox^ xor_comparison_string;
        //private: System::Windows::Forms::TextBox^ xor_results_string;



    public:
        MainForm(void)
        {
            InitializeComponent();
            base_hex_array = {};
            base_64_array = {};
            xor_compare = {};
            xor_results = {};
            plain_txt = {};
            key_txt = {};
            cipher_txt = {};
            single_xor_base64 = {};
            message_results = {};


            this->background_img->SizeMode = PictureBoxSizeMode::StretchImage;
            this->background_img->Dock = DockStyle::Fill;
            /*try {
                this->background_img->Image = Image::FromFile("C:/Users/ticau/source/repos/Project17/pic.jpg"); // Set the path to your image file
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading image: " + ex->Message);
            }*/
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

        //protected:

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
            this->xor_comparison_string = (gcnew System::Windows::Forms::TextBox());
            this->xor_result_string = (gcnew System::Windows::Forms::TextBox());
            this->Convert = (gcnew System::Windows::Forms::Button());
            this->Cancel = (gcnew System::Windows::Forms::Button());
            this->fixed_xor_btn = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->background_img = (gcnew System::Windows::Forms::PictureBox());
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background_img))->BeginInit();
            this->SuspendLayout();
            //
            // base_64
            //
            this->base_64->Location = System::Drawing::Point(182, 23);
            this->base_64->Name = L"base_64";
            this->base_64->Size = System::Drawing::Size(161, 20);
            this->base_64->TabIndex = 0;
            this->base_64->TextChanged += gcnew System::EventHandler(this, &MainForm::hash_input_TextChanged);
            //
            // base_hex
            //
            this->base_hex->Location = System::Drawing::Point(8, 20);
            this->base_hex->Name = L"base_hex";
            this->base_hex->Size = System::Drawing::Size(164, 20);
            this->base_hex->TabIndex = 1;
            this->base_hex->TextChanged += gcnew System::EventHandler(this, &MainForm::hash_base_hex_TextChanged);
            //
            // xor_comparison_string
            //
            this->xor_comparison_string->Location = System::Drawing::Point(8, 95);
            this->xor_comparison_string->Name = L"xor_comparison_string";
            this->xor_comparison_string->Size = System::Drawing::Size(161, 20);
            this->xor_comparison_string->TabIndex = 9;
            this->xor_comparison_string->TextChanged += gcnew System::EventHandler(this, &MainForm::xor_comparison_string_TextChanged);
            //
            // xor_result_string
            //
            this->xor_result_string->Location = System::Drawing::Point(180, 95);
            this->xor_result_string->Name = L"xor_result_string";
            this->xor_result_string->Size = System::Drawing::Size(161, 20);
            this->xor_result_string->TabIndex = 12;
            this->xor_result_string->TextChanged += gcnew System::EventHandler(this, &MainForm::xor_result_string_TextChanged);
            //
            // Convert
            //
            this->Convert->ForeColor = System::Drawing::SystemColors::ControlText;
            this->Convert->Location = System::Drawing::Point(8, 46);
            this->Convert->Name = L"Convert";
            this->Convert->Size = System::Drawing::Size(75, 23);
            this->Convert->TabIndex = 2;
            this->Convert->Text = L"Convert";
            this->Convert->UseVisualStyleBackColor = true;
            this->Convert->Click += gcnew System::EventHandler(this, &MainForm::hash_Click);
            //
            // Cancel
            //
            this->Cancel->Location = System::Drawing::Point(8, 455);
            this->Cancel->Name = L"Cancel";
            this->Cancel->Size = System::Drawing::Size(75, 23);
            this->Cancel->TabIndex = 3;
            this->Cancel->Text = L"Cancel";
            this->Cancel->UseVisualStyleBackColor = true;
            this->Cancel->Click += gcnew System::EventHandler(this, &MainForm::Cancel_Click);
            //
            // fixed_xor_btn
            //
            this->fixed_xor_btn->Location = System::Drawing::Point(8, 121);
            this->fixed_xor_btn->Name = L"fixed_xor_btn";
            this->fixed_xor_btn->Size = System::Drawing::Size(90, 23);
            this->fixed_xor_btn->TabIndex = 10;
            this->fixed_xor_btn->Text = L"Fixed Xor";
            this->fixed_xor_btn->UseVisualStyleBackColor = true;
            this->fixed_xor_btn->Click += gcnew System::EventHandler(this, &MainForm::xor_combination_Click);
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->label1->Location = System::Drawing::Point(12, 7);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(53, 13);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Base Hex";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(191, 7);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(46, 13);
            this->label2->TabIndex = 5;
            this->label2->Text = L"Base 64";
            //
            // background_img
            //
            this->background_img->Location = System::Drawing::Point(8, 12);
            this->background_img->Name = L"background_img";
            this->background_img->Size = System::Drawing::Size(286, 136);
            this->background_img->TabIndex = 6;
            this->background_img->TabStop = false;
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(9, 79);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(81, 13);
            this->label3->TabIndex = 8;
            this->label3->Text = L"Xor Comparison";
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(181, 79);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(56, 13);
            this->label4->TabIndex = 11;
            this->label4->Text = L"Xor Result";
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(5, 298);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(54, 13);
            this->label5->TabIndex = 13;
            this->label5->Text = L"Plain Text";
            //
            // plain_text_box
            //
            this->plain_text_box->Location = System::Drawing::Point(8, 314);
            this->plain_text_box->Name = L"plain_text_box";
            this->plain_text_box->Size = System::Drawing::Size(161, 20);
            this->plain_text_box->TabIndex = 14;
            this->plain_text_box->TextChanged += gcnew System::EventHandler(this, &MainForm::plain_text_box_TextChanged);
            //
            // label6
            //
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(332, 298);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(61, 13);
            this->label6->TabIndex = 15;
            this->label6->Text = L"Cipher Text";
            //
            // cipher_text_box
            //
            this->cipher_text_box->Location = System::Drawing::Point(335, 314);
            this->cipher_text_box->Name = L"cipher_text_box";
            this->cipher_text_box->Size = System::Drawing::Size(161, 20);
            this->cipher_text_box->TabIndex = 16;
            this->cipher_text_box->TextChanged += gcnew System::EventHandler(this, &MainForm::cipher_text_box_TextChanged);
            //
            // repeat_xor_btn
            //
            this->repeat_xor_btn->Location = System::Drawing::Point(8, 340);
            this->repeat_xor_btn->Name = L"repeat_xor_btn";
            this->repeat_xor_btn->Size = System::Drawing::Size(75, 23);
            this->repeat_xor_btn->TabIndex = 17;
            this->repeat_xor_btn->Text = L"Repeat Xor";
            this->repeat_xor_btn->UseVisualStyleBackColor = true;
            this->repeat_xor_btn->Click += gcnew System::EventHandler(this, &MainForm::repeat_xor_btn_Click);
            //
            // label7
            //
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(177, 298);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(25, 13);
            this->label7->TabIndex = 18;
            this->label7->Text = L"Key";
            //
            // key_text_box
            //
            this->key_text_box->Location = System::Drawing::Point(175, 314);
            this->key_text_box->Name = L"key_text_box";
            this->key_text_box->Size = System::Drawing::Size(154, 20);
            this->key_text_box->TabIndex = 19;
            this->key_text_box->TextChanged += gcnew System::EventHandler(this, &MainForm::key_text_box_TextChanged);
            //
            // add_file_btn
            //
            this->add_file_btn->Location = System::Drawing::Point(8, 272);
            this->add_file_btn->Name = L"add_file_btn";
            this->add_file_btn->Size = System::Drawing::Size(75, 23);
            this->add_file_btn->TabIndex = 20;
            this->add_file_btn->Text = L"Add File";
            this->add_file_btn->UseVisualStyleBackColor = true;
            this->add_file_btn->Click += gcnew System::EventHandler(this, &MainForm::add_file_btn_Click);
            //
            // file_xor_results
            //
            this->file_xor_results->Location = System::Drawing::Point(8, 246);
            this->file_xor_results->Name = L"file_xor_results";
            this->file_xor_results->Size = System::Drawing::Size(161, 20);
            this->file_xor_results->TabIndex = 21;
            this->file_xor_results->TextChanged += gcnew System::EventHandler(this, &MainForm::file_xor_results_TextChanged);
            //
            // label8
            //
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(5, 375);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(113, 13);
            this->label8->TabIndex = 22;
            this->label8->Text = L"Break Repeat Key Xor";
            //
            // hex_single_byte_cipher
            //
            this->hex_single_byte_cipher->Location = System::Drawing::Point(8, 173);
            this->hex_single_byte_cipher->Name = L"hex_single_byte_cipher";
            this->hex_single_byte_cipher->Size = System::Drawing::Size(161, 20);
            this->hex_single_byte_cipher->TabIndex = 23;
            this->hex_single_byte_cipher->TextChanged += gcnew System::EventHandler(this, &MainForm::hex_single_byte_cipher_TextChanged);
            //
            // label9
            //
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(9, 157);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(53, 13);
            this->label9->TabIndex = 24;
            this->label9->Text = L"Base Hex";
            //
            // message_box
            //
            this->message_box->Location = System::Drawing::Point(182, 173);
            this->message_box->Name = L"message_box";
            this->message_box->Size = System::Drawing::Size(159, 20);
            this->message_box->TabIndex = 25;
            this->message_box->TextChanged += gcnew System::EventHandler(this, &MainForm::message_box_TextChanged);
            //
            // Message
            //
            this->Message->AutoSize = true;
            this->Message->Location = System::Drawing::Point(187, 157);
            this->Message->Name = L"Message";
            this->Message->Size = System::Drawing::Size(50, 13);
            this->Message->TabIndex = 26;
            this->Message->Text = L"Message";
            //
            // single_byte_xor_btn
            //
            this->single_byte_xor_btn->Location = System::Drawing::Point(8, 199);
            this->single_byte_xor_btn->Name = L"single_byte_xor_btn";
            this->single_byte_xor_btn->Size = System::Drawing::Size(90, 23);
            this->single_byte_xor_btn->TabIndex = 27;
            this->single_byte_xor_btn->Text = L"Single Byte Xor";
            this->single_byte_xor_btn->UseVisualStyleBackColor = true;
            this->single_byte_xor_btn->Click += gcnew System::EventHandler(this, &MainForm::single_byte_xor_btn_Click);
            //
            // file_break_repeat_xor_change
            //
            this->file_break_repeat_xor_change->Location = System::Drawing::Point(8, 391);
            this->file_break_repeat_xor_change->Name = L"file_break_repeat_xor_change";
            this->file_break_repeat_xor_change->Size = System::Drawing::Size(151, 20);
            this->file_break_repeat_xor_change->TabIndex = 28;
            this->file_break_repeat_xor_change->TextChanged += gcnew System::EventHandler(this, &MainForm::file_break_repeat_xor_change_TextChanged);
            //
            // break_repeat_btn
            //
            this->break_repeat_btn->Location = System::Drawing::Point(8, 417);
            this->break_repeat_btn->Name = L"break_repeat_btn";
            this->break_repeat_btn->Size = System::Drawing::Size(75, 23);
            this->break_repeat_btn->TabIndex = 29;
            this->break_repeat_btn->Text = L"Add File";
            this->break_repeat_btn->UseVisualStyleBackColor = true;
            this->break_repeat_btn->Click += gcnew System::EventHandler(this, &MainForm::break_repeat_btn_Click);
            //
            // AES_btn
            //
            this->AES_btn->Location = System::Drawing::Point(165, 417);
            this->AES_btn->Name = L"AES_btn";
            this->AES_btn->Size = System::Drawing::Size(75, 23);
            this->AES_btn->TabIndex = 30;
            this->AES_btn->Text = L"Add File";
            this->AES_btn->UseVisualStyleBackColor = true;
            this->AES_btn->Click += gcnew System::EventHandler(this, &MainForm::AES_btn_Click);
            //
            // AEX_textbox
            //
            this->AEX_textbox->Location = System::Drawing::Point(165, 391);
            this->AEX_textbox->Name = L"AEX_textbox";
            this->AEX_textbox->Size = System::Drawing::Size(164, 20);
            this->AEX_textbox->TabIndex = 31;
            this->AEX_textbox->TextChanged += gcnew System::EventHandler(this, &MainForm::AEX_textbox_TextChanged);
            //
            // label10
            //
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(172, 375);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(63, 13);
            this->label10->TabIndex = 32;
            this->label10->Text = L"AES in ECB";
            //
            // Detect_AES_in_ECB_textbox
            //
            this->Detect_AES_in_ECB_textbox->Location = System::Drawing::Point(335, 391);
            this->Detect_AES_in_ECB_textbox->Name = L"Detect_AES_in_ECB_textbox";
            this->Detect_AES_in_ECB_textbox->Size = System::Drawing::Size(161, 20);
            this->Detect_AES_in_ECB_textbox->TabIndex = 33;
            //
            // label11
            //
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(332, 375);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(99, 13);
            this->label11->TabIndex = 34;
            this->label11->Text = L"Detect AES In ECB";
            //
            // Detect_AES_In_ECB_btn
            //
            this->Detect_AES_In_ECB_btn->Location = System::Drawing::Point(335, 417);
            this->Detect_AES_In_ECB_btn->Name = L"Detect_AES_In_ECB_btn";
            this->Detect_AES_In_ECB_btn->Size = System::Drawing::Size(75, 23);
            this->Detect_AES_In_ECB_btn->TabIndex = 35;
            this->Detect_AES_In_ECB_btn->Text = L"Add File";
            this->Detect_AES_In_ECB_btn->UseVisualStyleBackColor = true;
            this->Detect_AES_In_ECB_btn->Click += gcnew System::EventHandler(this, &MainForm::Detect_AES_In_ECB_btn_Click);
            //
            // label12
            //
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(9, 230);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(115, 13);
            this->label12->TabIndex = 36;
            this->label12->Text = L"Detect Single Char Xor";
            //
            // MainForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(519, 495);
            this->Controls->Add(this->label12);
            this->Controls->Add(this->Detect_AES_In_ECB_btn);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->Detect_AES_in_ECB_textbox);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->AEX_textbox);
            this->Controls->Add(this->AES_btn);
            this->Controls->Add(this->break_repeat_btn);
            this->Controls->Add(this->file_break_repeat_xor_change);
            this->Controls->Add(this->single_byte_xor_btn);
            this->Controls->Add(this->Message);
            this->Controls->Add(this->message_box);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->hex_single_byte_cipher);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->file_xor_results);
            this->Controls->Add(this->add_file_btn);
            this->Controls->Add(this->key_text_box);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->repeat_xor_btn);
            this->Controls->Add(this->cipher_text_box);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->plain_text_box);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->xor_result_string);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->fixed_xor_btn);
            this->Controls->Add(this->xor_comparison_string);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->Cancel);
            this->Controls->Add(this->base_hex);
            this->Controls->Add(this->base_64);
            this->Controls->Add(this->Convert);
            this->Controls->Add(this->background_img);
            this->Name = L"MainForm";
            this->Text = L"CryptoPal";
            this->Load += gcnew System::EventHandler(this, &MainForm::MyForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background_img))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        }
        // hex textbox
    private: System::Void hash_base_hex_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            String^ inputText = base_hex->Text;
            base_hex_array = inputText;
        }
        // base64 textbox
    private: System::Void hash_input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            String^ outputText = base_64_array;
        }
        //xor compare textbox
    private: System::Void xor_comparison_string_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            String^ inputText = xor_comparison_string->Text;
            xor_compare = inputText;
        }
        //xor result textbox
    private: System::Void xor_result_string_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            String^ output_text = xor_results;
        }
        //single byte cipher textbox
    private: System::Void hex_single_byte_cipher_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            String^ inputText = hex_single_byte_cipher->Text;
            single_xor_base64 = inputText;
        }
        //single byte cipher message textbox
    private: System::Void message_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            String^ output_text = message_results;
        }

        //key textbox
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

    private: System::Void file_break_repeat_xor_change_TextChanged(System::Object^ sender, System::EventArgs^ e) {

        }

    private: System::Void AEX_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

        }

    private: System::Void hash_Click(System::Object^ sender, System::EventArgs^ e) {
            base_hex_array = base_hex->Text;
            hex_to_base64();
        }

    private: System::Void xor_combination_Click(System::Object^ sender, System::EventArgs^ e) {
            base_hex_array = base_hex->Text;
            fixed_xor();
        }

    private: System::Void repeat_xor_btn_Click(System::Object^ sender, System::EventArgs^ e) {

            repeat_xor();
        }
        /// <summary>
    private: System::Void single_byte_xor_btn_Click(System::Object^ sender, System::EventArgs^ e) {
            single_byte_cipher();
        }

    private: System::Void file_xor_results_TextChanged(System::Object^ sender, System::EventArgs^ e) {

        }

    private: System::Void add_file_btn_Click(System::Object^ sender, System::EventArgs^ e) {
            single_char_xor();
        };

    private: System::Void break_repeat_btn_Click(System::Object^ sender, System::EventArgs^ e) {
            break_repeat_key_xor();
        }

    private: System::Void AES_btn_Click(System::Object^ sender, System::EventArgs^ e) {
            AES_in_ECB();
        }

    private: System::Void Detect_AES_In_ECB_btn_Click(System::Object^ sender, System::EventArgs^ e) {
            Detect_AES_in_ECB();
        }

    private: System::Void Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
            base_hex->Text = "";    // Clear the input text box
            base_64->Text = "";   // Clear the output text box
            key_text_box->Text = "";
            plain_text_box->Text = "";
            cipher_text_box->Text = "";
        }

        void MainForm::hex_to_base64()
        {
            ChallengeSolutions solution; //points to challange solution class
            // Check if base_hex_array is not empty
            System::String^ managedString = base_hex_array;
            //if (!String::IsNullOrEmpty(base_hex_array)) {
            // Convert System::String to std::string
            std::string hexString = msclr::interop::marshal_as<std::string>(managedString);

            // Task 1: Convert hex to base64
            std::string base64_string = solution.HexToBase64(hexString);

            // Update the hash_output text box with the base64 result
            base_64->Text = gcnew String(base64_string.c_str());
            //}
            // else {
            // Handle the case where base_hex_array is empty
            //base_64->Text = "Input is empty.";
            // }
        }

        void MainForm::fixed_xor()
        {
            ChallengeSolutions solution;
            System::String^ managedString = base_hex_array;
            std::string hexString = msclr::interop::marshal_as<std::string>(managedString);
            System::String^ managedString_2 = xor_compare;

            if (!String::IsNullOrEmpty(xor_compare)) {
                std::string xor_string = msclr::interop::marshal_as<std::string>(managedString);
                std::string xor_string_2 = msclr::interop::marshal_as<std::string>(managedString_2);
                std::string result_xor = solution.FixedXOR(xor_string, xor_string_2);
                xor_results = gcnew String(result_xor.c_str());
                xor_result_string->Text = gcnew String(result_xor.c_str());
            }
            else {
                // Handle the case where base_hex_array is empty
                xor_result_string->Text = "Input is empty.";
            }
        }

        void MainForm::single_byte_cipher()
        {
            ChallengeSolutions solution;
            System::String^ managedString = single_xor_base64;
            System::String^ managedString2 = message_results;

            if (!String::IsNullOrEmpty(single_xor_base64)) {
                std::string single_xor_base64_txt = msclr::interop::marshal_as<std::string>(managedString);
                std::string message = solution.SingleByteXORCipher(single_xor_base64_txt);
                message_results = gcnew String(message.c_str());
                message_box->Text = gcnew String(message.c_str());
            }
            else {
                message_box->Text = "Input is empty.";
            }

        }

        void MainForm::repeat_xor()
        {
            ChallengeSolutions solution;
            System::String^ managedString = plain_txt;
            std::string plain_txt_string = msclr::interop::marshal_as<std::string>(managedString);
            System::String^ managedString_2 = key_txt;
            if (!String::IsNullOrEmpty(key_txt)) {
                std::string key_txt_string = msclr::interop::marshal_as<std::string>(managedString_2);
                std::string cipher_result = solution.repeat_key_xor(plain_txt_string, key_txt_string);
                cipher_txt = gcnew String(cipher_result.c_str());
                cipher_text_box->Text = gcnew String(cipher_result.c_str());
            }
            else {
                cipher_text_box->Text = "Input is empty.";
            }

        }

        void MainForm::single_char_xor()
        {
            ChallengeSolutions solution;
            OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

            // Set the file filter and other properties as needed.
            openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            openFileDialog1->FilterIndex = 1;
            openFileDialog1->RestoreDirectory = true;
            String^ selectedFileName = openFileDialog1->FileName;


            if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                // Get the selected file name and pass it to DetectSingleCharXOR.

                // Convert the selectedFileName to a standard string (if needed).
                std::string standardStringFileName = msclr::interop::marshal_as<std::string>(selectedFileName);

                // Call the DetectSingleCharXOR function with the selected file name.
                std::string result = solution.DetectSingleCharXOR(standardStringFileName);

                // Display or process the result in the file_xor_results TextBox.
                // Assuming "file_xor_results" is the name of your TextBox:
                file_xor_results->Text = gcnew String(result.c_str());
            };
        }

        void MainForm::break_repeat_key_xor()
        {
            ChallengeSolutions solution;
            OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

            // Set the file filter and other properties as needed.
            openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            openFileDialog1->FilterIndex = 1;
            openFileDialog1->RestoreDirectory = true;
            // Get the selected file name and pass it to DetectSingleCharXOR.
            String^ selectedFileName = openFileDialog1->FileName;


            if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

                // Convert the selectedFileName to a standard string (if needed).
                std::string standardStringFileName = msclr::interop::marshal_as<std::string>(selectedFileName);

                // Call the DetectSingleCharXOR function with the selected file name.
                std::string result = solution.BreakRepeatingKeyXOR();

                // Display or process the result in the file_xor_results TextBox.
                // Assuming "file_xor_results" is the name of your TextBox:
                file_break_repeat_xor_change->Text = gcnew String(result.c_str());
            };

        }

        void MainForm::AES_in_ECB()
        {
            ChallengeSolutions solution;
            OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

            // Set the file filter and other properties as needed.
            openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            openFileDialog1->FilterIndex = 1;
            openFileDialog1->RestoreDirectory = true;
            String^ selectedFileName = openFileDialog1->FileName;

            if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

                // Convert the selectedFileName to a standard string (if needed).
                std::string standardStringFileName = msclr::interop::marshal_as<std::string>(selectedFileName);

                // Call the DetectSingleCharXOR function with the selected file name.
                std::string result = solution.AES_ECBMode();

                // Display or process the result in the file_xor_results TextBox.
                // Assuming "file_xor_results" is the name of your TextBox:
                AEX_textbox->Text = gcnew String(result.c_str());
            };

        }

        void MainForm::Detect_AES_in_ECB()
        {
            ChallengeSolutions solution;
            OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

            // Set the file filter and other properties as needed.
            openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            openFileDialog1->FilterIndex = 1;
            openFileDialog1->RestoreDirectory = true;
            String^ selectedFileName = openFileDialog1->FileName;

            if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

                // Convert the selectedFileName to a standard string (if needed).
                std::string standardStringFileName = msclr::interop::marshal_as<std::string>(selectedFileName);

                // Call the DetectSingleCharXOR function with the selected file name.
                std::string result = solution.DetectAES_ECBMode();

                // Display or process the result in the file_xor_results TextBox.
                // Assuming "file_xor_results" is the name of your TextBox:
                Detect_AES_in_ECB_textbox->Text = gcnew String(result.c_str());
            }

        };
    };
}