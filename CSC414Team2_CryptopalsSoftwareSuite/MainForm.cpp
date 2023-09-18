#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CSC414Team2CryptopalsSoftwareSuite::MainForm form;
	Application::Run(% form);
}