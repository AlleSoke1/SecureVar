#include <windows.h>
#include <iostream>
#include <string>
#include "CProtectedVar.hpp"

//Key used to encrypt the variable
unsigned char g_Keys[6] = { "ABCD\0" };

int main(int argc, char** argv)
{
	//Protected variable
	CProtectedVar<int> nVar(0);

	std::cout << "Enter a number to assign to the variable: ";
	
	int nTemp = 0;
	std::cin >> nTemp;
	nVar = nTemp;

	nTemp = 0;


	while (1)
	{
		std::cout << "Chosen Number: " << std::to_string(nVar.get()) << " at &" << &nVar << std::endl;
		Sleep(1000);
	}

	return 0;
}