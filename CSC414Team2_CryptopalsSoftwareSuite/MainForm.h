#pragma once
#include <msclr/marshal_cppstd.h>


namespace Project17 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    private:
        String^ base_hex_array;
    private: System::Windows::Forms::PictureBox^ background_img;
        String^ base_64_array;
    public:
        MyForm(void)
        {
            InitializeComponent();
            base_hex_array = {};
            base_64_array = {};

            this->background_img->SizeMode = PictureBoxSizeMode::StretchImage;
            this->background_img->Dock = DockStyle::Fill;
            try {
                this->background_img->Image = Image::FromFile("C:/Users/ticau/source/repos/Project17/pic.jpg"); // Set the path to your image file
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading image: " + ex->Message);
            }
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
        // The PerformConversion() function you provided
        void MyForm::PerformConversion() {
            // Check if base_hex_array is not empty
            if (!String::IsNullOrEmpty(base_hex_array)) {
                // Convert System::String to std::string
                System::String^ managedString = base_hex_array;
                std::string hexString = msclr::interop::marshal_as<std::string>(managedString);

                // Task 1: Convert hex to bytes using the function from CryptoOperations.cpp
                std::vector<unsigned char> bytes = hexToBytes(hexString);

                // Task 2: Convert bytes to base64 using the function from CryptoOperations.cpp
                std::string base64String = bytesToBase64(bytes);

                // Update the base_64_array member (optional)
                base_64_array = gcnew String(base64String.c_str());

                // Update the hash_output text box with the base64 result
                hash_output->Text = gcnew String(base64String.c_str());
            }
            else {
                // Handle the case where base_hex_array is empty
                hash_output->Text = "Input is empty.";
            }
        }
    private: System::Windows::Forms::TextBox^ hash_input;
    private: System::Windows::Forms::TextBox^ hash_output;
    private: System::Windows::Forms::Button^ Convert;
    private: System::Windows::Forms::Button^ Cancel;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
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
            this->hash_input = (gcnew System::Windows::Forms::TextBox());
            this->hash_output = (gcnew System::Windows::Forms::TextBox());
            this->Convert = (gcnew System::Windows::Forms::Button());
            this->Cancel = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->background_img = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background_img))->BeginInit();
            this->SuspendLayout();
            //
            // hash_input
            //
            this->hash_input->Location = System::Drawing::Point(12, 60);
            this->hash_input->Name = L"hash_input";
            this->hash_input->Size = System::Drawing::Size(176, 20);
            this->hash_input->TabIndex = 0;
            this->hash_input->TextChanged += gcnew System::EventHandler(this, &MyForm::hash_input_TextChanged);
            //
            // hash_output
            //
            this->hash_output->Location = System::Drawing::Point(12, 23);
            this->hash_output->Name = L"hash_output";
            this->hash_output->Size = System::Drawing::Size(176, 20);
            this->hash_output->TabIndex = 1;
            this->hash_output->TextChanged += gcnew System::EventHandler(this, &MyForm::hash_output_TextChanged);
            //
            // Convert
            //
            this->Convert->ForeColor = System::Drawing::SystemColors::ControlText;
            this->Convert->Location = System::Drawing::Point(12, 96);
            this->Convert->Name = L"Convert";
            this->Convert->Size = System::Drawing::Size(75, 23);
            this->Convert->TabIndex = 2;
            this->Convert->Text = L"Convert";
            this->Convert->UseVisualStyleBackColor = true;
            this->Convert->Click += gcnew System::EventHandler(this, &MyForm::hash_Click);
            //
            // Cancel
            //
            this->Cancel->Location = System::Drawing::Point(113, 96);
            this->Cancel->Name = L"Cancel";
            this->Cancel->Size = System::Drawing::Size(75, 23);
            this->Cancel->TabIndex = 3;
            this->Cancel->Text = L"Cancel";
            this->Cancel->UseVisualStyleBackColor = true;
            this->Cancel->Click += gcnew System::EventHandler(this, &MyForm::Cancel_Click);
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
            this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(12, 46);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(46, 13);
            this->label2->TabIndex = 5;
            this->label2->Text = L"Base 64";
            //
            // background_img
            //
            this->background_img->Location = System::Drawing::Point(-1, -5);
            this->background_img->Name = L"background_img";
            this->background_img->Size = System::Drawing::Size(286, 136);
            this->background_img->TabIndex = 6;
            this->background_img->TabStop = false;
            this->background_img->Click += gcnew System::EventHandler(this, &MyForm::background_img_Click);
            //
            // MyForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(280, 127);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->Cancel);
            this->Controls->Add(this->hash_output);
            this->Controls->Add(this->hash_input);
            this->Controls->Add(this->Convert);
            this->Controls->Add(this->background_img);
            this->Name = L"MyForm";
            this->Text = L"CryptoPal";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->background_img))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        }
    private: System::Void hash_Click(System::Object^ sender, System::EventArgs^ e) {
            base_hex_array = hash_input->Text;
        }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
        }
    private: System::Void hash_output_TextChanged(System::Object^ sender, System::EventArgs^ e) {

        }
    private: System::Void Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
            hash_input->Text = "";    // Clear the input text box
            hash_output->Text = "";   // Clear the output text box
        }
    private: System::Void background_img_Click(System::Object^ sender, System::EventArgs^ e) {

        }

    private: System::Void hash_input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        }
    };
};


