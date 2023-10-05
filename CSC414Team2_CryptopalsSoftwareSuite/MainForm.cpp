#define NOMINMAX // fixes collision with std::numeric_limits?
#pragma warning(disable : 4996)

#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CSC414Team2CryptopalsSoftwareSuite::MainForm form;
	Application::Run(% form);
}