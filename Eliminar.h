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
void eliminarCancion(vector<string>& listMusic)
{
    cout << "Lista de agregados para reproducion" << endl;
    for (unsigned int i = 0; i < listMusic.size(); i++)
    {
        cout << "\t"; cout.put(14); cout << " " << listMusic[i] << endl;
    }
    if (listMusic.size() == 0)
        cout << "\tNo hay canciones en la lista de reproduccion" << endl;
    else
    {
        string nombre;
        cout << "\nIngrese el nombre completo de la cancion a eliminar: ";
        cin.ignore();
        getline(cin, nombre);
        vector<string>::iterator it;
        bool t1 = false;
        for (unsigned int i = 0; i < listMusic.size(); i++)
        {
            if (listMusic[i] == nombre)
            {
                it = listMusic.begin() + i;
                listMusic.erase(it);
                t1 = true;
            }
        }
        //Cuando tengo mas de una cancion agregada
        if (t1 && listMusic.size() > 0)
        {
            cout << "Lista de actualizada de agregados para reproducion" << endl;
            for (unsigned int i = 0; i < listMusic.size(); i++)
            {
                cout << "\t"; cout.put(14); cout << " " << listMusic[i] << endl;
            }
        }
        else if (!t1)
            cout << "\tNiguna cancion con el nombre buscado" << endl;//musica12
          //
        else
            cout << "\tNo hay canciones en la lista de reproduccion" << endl;
    }
}