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
using namespace std;
template<typename T1>
bool buscado = T1;
void agregarCancion(vector<string>& listMusic, vector<string>& musicFound)
{
    cout << "Lista de agregados para reproducion" << endl;
    for (unsigned int i = 0; i < listMusic.size(); i++)
    {
        cout << "\t"; cout.put(14); cout << " " << listMusic[i] << endl;
    }
    if (listMusic.size() == 0)
        cout << "\tNo hay canciones en la lista de reproduccion" << endl;
    string music;
    cout << "\nIngrese el nombre de la cancion (ejemplo music.wav): ";
    cin.ignore();
    getline(cin, music);
    bool T1 = false;
    for (unsigned int i = 0; i < musicFound.size(); i++)
    {
        if (music == musicFound[i])
        {
            listMusic.push_back(music);
            T1 = true;
            break;
        }
    }
    if (!T1)
        cout << "\nCancion no encontrada" << endl;
    else
        cout << "\nCorrecto, agregada" << endl;

}
