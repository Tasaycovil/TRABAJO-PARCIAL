#pragma comment (lib, "winmm.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include "OrdLista.h"
#include "OrdAgregar.h"

using namespace std;


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
void reproducirCancion(vector<string> &listMusic)
{
  for(unsigned int i=0; i<listMusic.size();i++ )
  {
    wstring temp = wstring(listMusic[i].begin(), listMusic[i].end());
    LPCWSTR wideString = temp.c_str();
    cout<<"Pista actual: ";cout.put(14);cout<<" "<<listMusic[i]<<endl;
    PlaySound(wideString, NULL, SND_FILENAME | SND_ASYNC);
    cout<<"\t>>>Siguiente cancion, pulse cualquier tecla"<<endl;
    cout<<"\t  ";
    system("Pause");
  }
  if(listMusic.size() == 0)
    cout<<"\n\tNo hay canciones en la lista de reproduccion"<<endl;
  else
    PlaySound(NULL, 0, 0);
}

using namespace System;

int main()
{
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
              cout << "5. Salir" << endl << endl;
			  cout << "INGRESE SU ELECCION: ";
			  cin >> opc;
		  } while (opc < 1 || opc>5);
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
      }
    }
    cout<<"Fin del programa"<<endl;
    system("pause");

    _getch();

	}