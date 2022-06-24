#include <iostream>
#include "FuncionesMain.h"
#include "OrdLista.h"
#include "OrdAgregar.h"
#include "OrdReproducir.h"
#include "OrdAvanzados.h" 
#include "Dataset.h"
#include "HashEntidad.h"
#include "HashTabla.h"

using namespace std;
using namespace System;


int main()
{
    int opc;
	bool repetir = true;
    vector<string> listMusic;
    vector<string> musicFound;
    //metodo quicksort 
    //numero de canciones para quicksort
    int n = 5;
    //caso de valor kesimo 2 para quickselect
    int k = 2;

    while(true)
    {
      do
		  {
          cout << "**********      BIENVENIDO A PLAYMUSIC  *******************" << endl;
          cout << "**********       MENU DE OPCIONES       *******************" << endl;
	      cout << "*    1. LISTA DE CANCIONES ENCONTRADAS                    *" << endl;
		  cout << "*    2. AGREGAR CANCION PARA REPRODUCIR                   *" << endl;
		  cout << "*    3. ELIMINAR CANCION DE LA LISTA DE REPRODUCCION      *" << endl;
		  cout << "*    4. REPRODUCIR CANCION                                *" << endl;
          cout << "*    5. IMPRESION DE LA LISTA DE CANCIONES POR QUICKSORT  *" << endl;
          cout << "*    6. LISTA DE ELECCION DE CANCIONES ALEATORIAS         *" << endl;
          cout << "*    7. INSERCION POR HASHTABLE                           *" << endl;
          cout << "*    8. Salir                                             *" << endl;
          cout << "***********************************************************" << endl;
	      cout << "INGRESE SU ELECCION : ";
			  cin >> opc;
		  } 
      while (opc < 1 || opc>7);
      if(opc==8) break;

      switch(opc)
      {
        case 1:
            cout << "\nCanciones encontradas:\n";
            listarCanciones(musicFound);
          break;
        case 2:agregarCancion(listMusic,musicFound);
          break;
        case 3:eliminarCancion(listMusic);
          break;
        case 4:reproducirCancion(listMusic);
          break;
        case 5:
            //quicksort
            quicksort(musicFound, 0, n - 1);
            cout << "\nArreglo de canciones ordenado por quicksort :\n";
            for (short i = 0; i < n; i++)
                cout << musicFound[i] << " " << "\n";
            break;
            //quickselect
            /*
            int e = quickselect(listMusic, 0, n - 1, k);
            for (int i = 0; i < n; i++)
                cout << listMusic[i] << " ";
            cout << "\nArreglo de canciones ordenado por quickselect cuando el kesimo elemento es 2 :\n" << e;
            break;*/
        case 6:
            cout << "Escoge el numero de canciones aleatorias" << endl;
            cin >> n;
            fflush(stdin);
            DatasetCancion(listMusic);
            break;
          break;
        case 7:
            RetornoTabla();
            break;
      }
    }
    cout<<"FIN DEL PROGRAMA PLAYMUSIC"<<endl;
    system("pause");
    cin.get();
	}
