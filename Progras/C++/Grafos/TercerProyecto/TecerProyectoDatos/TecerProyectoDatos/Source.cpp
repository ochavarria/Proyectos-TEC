#include <iostream>
#include <Windows.h>
#include "TecerProyecto.h"

using std::cout;
using std::endl;
using std::cin;


/*int main()
{
cin.get();
return 0;
}*/

[STAThread]

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application::Run(gcnew TecerProyecto());
}
