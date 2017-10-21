#include <iostream>
#include <Windows.h>
#include "VentanaOceanoP1D1.h"

using std::cout;
using std::endl;
using std::cin;


[STAThread]

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application::Run(gcnew VentanaOceanoP1D1());
}

