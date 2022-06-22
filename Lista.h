#pragma once
#pragma comment (lib, "winmm.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <vector>
using namespace std;
void listarCanciones(vector<string>& musicFound)
{
    cout << endl;
    string myText;
    system("cd.. & dir *.wav /b /s > Debug\\lista.txt");
    system("cd.. & dir *.wav /b /s > PlayMusic\\lista.txt");
    ifstream archivo("lista.txt");
    int indice = 0;
    bool estado = false;
    while (getline(archivo, myText))
    {
        int pos;
        for (unsigned int i = 0; i < myText.size(); i++)
        {
            if (myText[i] == '\\') pos = i;
            estado = true;
        }

        cout << "\t"; cout.put(14); cout << " " << myText.substr(pos + 1) << endl;
        musicFound.push_back(myText.substr(pos + 1));
    }
    archivo.close();
    if (!estado)
        cout << "\n\tLista no encontrada" << endl;
}