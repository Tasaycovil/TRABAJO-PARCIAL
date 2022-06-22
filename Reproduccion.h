#pragma once
#pragma comment (lib, "winmm.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include "Lista.h"
#include "Agregar.h"
using namespace std;
void reproducirCancion(vector<string>& listMusic)
{
    for (unsigned int i = 0; i < listMusic.size(); i++)
    {
        wstring temp = wstring(listMusic[i].begin(), listMusic[i].end());
        LPCWSTR wideString = temp.c_str();
        cout << "Pista actual: "; cout.put(14); cout << " " << listMusic[i] << endl;
        PlaySound(wideString, NULL, SND_FILENAME | SND_ASYNC);
        cout << "\t>>>Siguiente cancion, pulse cualquier tecla" << endl;
        cout << "\t  ";
        system("Pause");
    }
    if (listMusic.size() == 0)
        cout << "\n\tNo hay canciones en la lista de reproduccion" << endl;
    else
        PlaySound(NULL, 0, 0);
}