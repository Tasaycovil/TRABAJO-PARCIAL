#pragma comment (lib, "winmm.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <random>
#include <time.h>
#include "OrdLista.h"
#include "OrdAgregar.h"
#include "OrdAvanzados.h" 
using namespace std;

/*/ Ordenamiento Avanzados
int n=4;
//se usara el vector listmusic como parametro de tamaño del arreglo
//ordenamiento quicksort
//impresion del arreglo por metodo quicksort
quicksort(listMusic, 0, n - 1);
    cout << "\nArreglo de canciones ordenado por quicksort :\n";
    for (short i = 0; i < n; i++)
        cout << listMusic[i] << " ";
//ordenamiento quickselect
//se pondra kesimo de valor 2 mitad del tamaño del valor del arreglo ingresado(4)
//impresion del arreglo por metodo quickselect
int k=2;
int e = quickselect(listMusic, 0, n - 1, k);
    for (int i = 0; i < n; i++)
        cout << listMusic[i] << " ";
    cout << "\n Cuando la cancion con valor del kesimo elemento es 2: " << e;
*/


void listarCanciones(vector<string> &musicFound)
{
  cout<<endl;
  string myText;
  system("cd.. & dir *.wav /b /s > Debug\\lista.txt");
  system("cd.. & dir *.wav /b /s > PlayMusic\\lista.txt");
  ifstream archivo("lista.txt");
  int indice=0;
  bool estado= false;
  while(getline(archivo,myText))
  {
    int pos;
    for(unsigned int i = 0; i<myText.size(); i++)
    {
      if(myText[i]=='\\') pos = i;
      estado=true;
    }

    cout<<"\t";cout.put(14);cout<<" "<<myText.substr(pos+1)<<endl;
    musicFound.push_back(myText.substr(pos+1));
  }
  archivo.close();
  if(!estado)
    cout<<"\n\tLista no encontrada"<<endl;
}

template<typename T1>
bool buscado=T1;
void agregarCancion(vector<string> &listMusic,vector<string> &musicFound)
{
  cout<<"Lista de agregados para reproducion"<<endl;
  for(unsigned int i=0; i<listMusic.size();i++ )
  {
    cout<<"\t";cout.put(14);cout<<" "<<listMusic[i]<<endl;
  }
  if(listMusic.size() == 0)
    cout<<"\tNo hay canciones en la lista de reproduccion"<<endl;
  string music;
  cout<<"\nIngrese el nombre de la cancion (ejemplo music.wav): ";
  cin.ignore();
  getline(cin,music);
  bool T1=false;
  for(unsigned int i=0; i<musicFound.size();i++ )
  {
    if(music==musicFound[i])
    {
      listMusic.push_back(music);
      T1= true;
      break;
    }
  }
  if(!T1)
    cout<<"\nCancion no encontrada"<<endl;
  else
    cout<<"\nCorrecto, agregada"<<endl;

}
void eliminarCancion(vector<string> &listMusic)
{
  cout<<"Lista de agregados para reproducion"<<endl;
  for(unsigned int i=0; i<listMusic.size();i++ )
  {
    cout<<"\t";cout.put(14);cout<<" "<<listMusic[i]<<endl;
  }
  if(listMusic.size() == 0)
    cout<<"\tNo hay canciones en la lista de reproduccion"<<endl;
  else
  {
    string nombre;
    cout<<"\nIngrese el nombre completo de la cancion a eliminar: ";
    cin.ignore();
    getline(cin,nombre);
    vector<string>::iterator it;
    bool t1=false;
    for(unsigned int i=0; i<listMusic.size();i++ )
    {
      if(listMusic[i]==nombre)
      {
        it = listMusic.begin()+i;
        listMusic.erase(it);
        t1= true;
      }
    }
    //Cuando tengo mas de una cancion agregada
    if(t1 && listMusic.size()> 0)
    {
      cout<<"Lista de actualizada de agregados para reproducion"<<endl;
      for(unsigned int i=0; i<listMusic.size();i++ )
      {
        cout<<"\t";cout.put(14);cout<<" "<<listMusic[i]<<endl;
      }
    }
    else if(!t1)
      cout<<"\tNiguna cancion con el nombre buscado"<<endl;//musica12
    //
    else
      cout<<"\tNo hay canciones en la lista de reproduccion"<<endl;
  }
}
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

struct cancion {
    string nombre;
    string url;
    int id;
    struct cancion* sig;
};

cancion* crear_cancion(int numero, string name, string link) {
    struct cancion* n;
    n = (cancion*)malloc(sizeof(cancion));
    n->id = numero;
    n->sig = NULL;
    n->nombre = name;
    n->url = link;
    return n;
}

cancion* insertar_nodo(int numero, string nombre, string link, cancion* cabeza) {
    struct cancion* nodo, * aux;
    nodo = crear_cancion(numero, nombre, link);
    if (cabeza == NULL)
        return nodo;
    else
    {
        for (aux = cabeza; aux->sig != NULL; aux = aux->sig);
        aux->sig = nodo;
        return cabeza;
    }
}

using namespace System;

int main()
{
    cancion* cabeza = NULL;
    cancion* aux, * aux2;
    int i;
    int n;
    cancion c1;
    const char* url;
    int opc;
	  bool repetir = true;
    vector<string> listMusic;
    vector<string> musicFound;
    while(true)
    {
      do
		  {
			  cout << "MENU " << endl << endl;
			  cout << "1. Lista de canciones " << endl;
			  cout << "2. Agregar cancion" << endl;
			  cout << "3. Eliminar cancion " << endl;
			  cout << "4. Reproducir cancion" << endl;
              cout << "5. Lista de elección de canciones " << endl;
              cout << "6. Salir" << endl << endl;
			  cout << "INGRESE SU ELECCION: ";
			  cin >> opc;
		  } while (opc < 1 || opc>6);
      if(opc==5) break;

      switch(opc)
      {
        case 1:
          listarCanciones(musicFound);
          break;
        case 2:
          agregarCancion(listMusic,musicFound);
          break;
        case 3:
          eliminarCancion(listMusic);
          break;
        case 4:
          reproducirCancion(listMusic);
          break;
        case 5:
            cout << "¿Cuantas canciones tendra tu lista? Puedes escoger un numero entre 1 y 10" << endl;
            cin >> i;
            fflush(stdin);
            if (i == 1)
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
            else if (i == 2) {
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
                cabeza = insertar_nodo(2, "John Legend - All of me", "&#8234;D:\Dámaris\Song.wav\\John Legend - All of me.wav", cabeza);
            }
            else if (i == 3) {
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
                cabeza = insertar_nodo(2, "John Legend - All of me", "&#8234;D:\Dámaris\Song.wav\\John Legend - All of me.wav", cabeza);
                cabeza = insertar_nodo(3, "Lewis Capaldi - Someone you loved", "&#8234;D:\Dámaris\Song.wav\\Lewis Capaldi - Someone you loved.wav", cabeza);
            }
            else if (i == 4) {
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
                cabeza = insertar_nodo(2, "John Legend - All of me", "&#8234;D:\Dámaris\Song.wav\\John Legend - All of me.wav", cabeza);
                cabeza = insertar_nodo(3, "Lewis Capaldi - Someone you loved", "&#8234;D:\Dámaris\Song.wav\\Lewis Capaldi - Someone you loved.wav", cabeza);
                cabeza = insertar_nodo(4, "Jessica Mauboy - Little Things", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Little Things.wav", cabeza);
            }
            else if (i == 5) {
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
                cabeza = insertar_nodo(2, "John Legend - All of me", "&#8234;D:\Dámaris\Song.wav\\John Legend - All of me.wav", cabeza);
                cabeza = insertar_nodo(3, "Lewis Capaldi - Someone you loved", "&#8234;D:\Dámaris\Song.wav\\Lewis Capaldi - Someone you loved.wav", cabeza);
                cabeza = insertar_nodo(4, "Jessica Mauboy - Little Things", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Little Things.wav", cabeza);
                cabeza = insertar_nodo(5, "Jessica Mauboy - Never Be the Same", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Never Be the Same.wav", cabeza);
            }
            else if (i == 6) {
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
                cabeza = insertar_nodo(2, "John Legend - All of me", "&#8234;D:\Dámaris\Song.wav\\John Legend - All of me.wav", cabeza);
                cabeza = insertar_nodo(3, "Lewis Capaldi - Someone you loved", "&#8234;D:\Dámaris\Song.wav\\Lewis Capaldi - Someone you loved.wav", cabeza);
                cabeza = insertar_nodo(4, "Jessica Mauboy - Little Things", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Little Things.wav", cabeza);
                cabeza = insertar_nodo(5, "Jessica Mauboy - Never Be the Same", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Never Be the Same.wav", cabeza);
                cabeza = insertar_nodo(6, "The Cab - Angel with a Shotgun", "&#8234;D:\Dámaris\Song.wav\\The Cab - Angel with a Shotgun.wav", cabeza);
            }
            else if (i == 7) {
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
                cabeza = insertar_nodo(2, "John Legend - All of me", "&#8234;D:\Dámaris\Song.wav\\John Legend - All of me.wav", cabeza);
                cabeza = insertar_nodo(3, "Lewis Capaldi - Someone you loved", "&#8234;D:\Dámaris\Song.wav\\Lewis Capaldi - Someone you loved.wav", cabeza);
                cabeza = insertar_nodo(4, "Jessica Mauboy - Little Things", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Little Things.wav", cabeza);
                cabeza = insertar_nodo(5, "Jessica Mauboy - Never Be the Same", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Never Be the Same.wav", cabeza);
                cabeza = insertar_nodo(6, "The Cab - Angel with a Shotgun", "&#8234;D:\Dámaris\Song.wav\\The Cab - Angel with a Shotgun.wav", cabeza);
                cabeza = insertar_nodo(7, "musica5", "&#8234;D:\Dámaris\Song.wav\\musica5.wav", cabeza);
            }
            else if (i == 8) {
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
                cabeza = insertar_nodo(2, "John Legend - All of me", "&#8234;D:\Dámaris\Song.wav\\John Legend - All of me.wav", cabeza);
                cabeza = insertar_nodo(3, "Lewis Capaldi - Someone you loved", "&#8234;D:\Dámaris\Song.wav\\Lewis Capaldi - Someone you loved.wav", cabeza);
                cabeza = insertar_nodo(4, "Jessica Mauboy - Little Things", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Little Things.wav", cabeza);
                cabeza = insertar_nodo(5, "Jessica Mauboy - Never Be the Same", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Never Be the Same.wav", cabeza);
                cabeza = insertar_nodo(6, "The Cab - Angel with a Shotgun", "&#8234;D:\Dámaris\Song.wav\\The Cab - Angel with a Shotgun.wav", cabeza);
                cabeza = insertar_nodo(7, "musica5", "&#8234;D:\Dámaris\Song.wav\\musica5.wav", cabeza);
                cabeza = insertar_nodo(8, "James Bay - Move together", "&#8234;D:\Dámaris\Song.wav\\James Bay - Move together.wav", cabeza);
            }
            else if (i == 9) {
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
                cabeza = insertar_nodo(2, "John Legend - All of me", "&#8234;D:\Dámaris\Song.wav\\John Legend - All of me.wav", cabeza);
                cabeza = insertar_nodo(3, "Lewis Capaldi - Someone you loved", "&#8234;D:\Dámaris\Song.wav\\Lewis Capaldi - Someone you loved.wav", cabeza);
                cabeza = insertar_nodo(4, "Jessica Mauboy - Little Things", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Little Things.wav", cabeza);
                cabeza = insertar_nodo(5, "Jessica Mauboy - Never Be the Same", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Never Be the Same.wav", cabeza);
                cabeza = insertar_nodo(6, "The Cab - Angel with a Shotgun", "&#8234;D:\Dámaris\Song.wav\\The Cab - Angel with a Shotgun.wav", cabeza);
                cabeza = insertar_nodo(7, "musica5", "&#8234;D:\Dámaris\Song.wav\\musica5.wav", cabeza);
                cabeza = insertar_nodo(8, "James Bay - Move together", "&#8234;D:\Dámaris\Song.wav\\James Bay - Move together.wav", cabeza);
                cabeza = insertar_nodo(9, "Chord Overstreet - Hold On", "&#8234;D:\Dámaris\Song.wav\\Chord Overstreet - Hold On.wav", cabeza);
            }
            else if (i == 10) {
                cabeza = insertar_nodo(1, "Christina Perri - Human", "D:\Dámaris\Song.wav\\Christina Perri - Human.wav", cabeza);
                cabeza = insertar_nodo(2, "John Legend - All of me", "&#8234;D:\Dámaris\Song.wav\\John Legend - All of me.wav", cabeza);
                cabeza = insertar_nodo(3, "Lewis Capaldi - Someone you loved", "&#8234;D:\Dámaris\Song.wav\\Lewis Capaldi - Someone you loved.wav", cabeza);
                cabeza = insertar_nodo(4, "Jessica Mauboy - Little Things", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Little Things.wav", cabeza);
                cabeza = insertar_nodo(5, "Jessica Mauboy - Never Be the Same", "&#8234;D:\Dámaris\Song.wav\\Jessica Mauboy - Never Be the Same.wav", cabeza);
                cabeza = insertar_nodo(6, "The Cab - Angel with a Shotgun", "&#8234;D:\Dámaris\Song.wav\\The Cab - Angel with a Shotgun.wav", cabeza);
                cabeza = insertar_nodo(7, "musica5", "&#8234;D:\Dámaris\Song.wav\\musica5.wav", cabeza);
                cabeza = insertar_nodo(8, "James Bay - Move together", "&#8234;D:\Dámaris\Song.wav\\James Bay - Move together.wav", cabeza);
                cabeza = insertar_nodo(9, "Chord Overstreet - Hold On", "&#8234;D:\Dámaris\Song.wav\\Chord Overstreet - Hold On.wav", cabeza);
                cabeza = insertar_nodo(10, "Jennie-Can't Take My Eyes Off You", "&#8234;D:\Dámaris\Song.wav\\Jennie-Can't Take My Eyes Off You.wav", cabeza);
            }
          break;
      }
    }
    cout<<"Fin del programa"<<endl;
    system("pause");

    _getch();

	}
