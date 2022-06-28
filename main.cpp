#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Lista.h"
#include "Agregar.h"
#include "Eliminar.h"
#include "Reproduccion.h"
#include "OrdLista.h"
#include "OrdAgregar.h"
#include "OrdAvanzados.h" 
#include "HashTabla.h"
#include "HashEntidad.h"
#include "Dataset.h"
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
    while (true)
    {
        do
        {
            cout << "****      BIENVENIDO A PLAYMUSIC  *******" << endl;
            cout << "****       MENU DE OPCIONES       *******" << endl;
            cout << "*    1. LISTA DE CANCIONES                  *" << endl;
            cout << "*    2. AGREGAR CANCION PARA REPRODUCIR                   *" << endl;
            cout << "*    3. ELIMINAR CANCION DE LA LISTA DE REPRODUCCION      *" << endl;
            cout << "*    4. REPRODUCIR CANCION                                *" << endl;
            cout << "*    5. IMPRESION DE LA LISTA DE CANCIONES POR QUICKSORT  *" << endl;
            cout << "*    6. RANGO DE CANCIONES  *" << endl;
            cout << "*    7. INSERCION POR HASHTABLE        *" << endl;
            cout << "*    8. Salir                                             *" << endl;
            cout << "*********************" << endl;
            cout << "INGRESE SU ELECCION : ";
            cin >> opc;
        }       while (opc < 1 || opc>8);
        if (opc == 8) break;

        switch (opc)
        {
        case 1:
            cout << "\nCanciones encontradas:\n";
            listarCanciones(musicFound);
            break;
        case 2:agregarCancion(listMusic, musicFound);
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
            cout << "Numero de canciones aleatorias" << endl;
            cin >> n;
            /*PlaySound(TEXT("All of me.wav"), NULL,SND_SYNC);
            cout << "\t>>>Siguiente cancion, pulse cualquier tecla" << endl;
            cout << "\t  ";
            system("Pause");
            /*char soundfile[] = "D:\Dámaris\Song.wav\\All of me.wav";
            cout << PlaySound((LPCWSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC);
            system("pause");
            /*fflush(stdin);*/
            void Datasetcancion(); {
                if (n == 1) {
                    cout << "Musica actual: "; cout.put(14); cout << " " << "Human" << endl;
                    cout << "\t>>>Si desea salir, pulse cualquier tecla" << endl;
                    cout << "\t  ";
                    PlaySound(TEXT("Human1.wav"), NULL, SND_SYNC);
                    system("Pause");
                }
                else if (n == 2) {
                    cout << "Musica actual: "; cout.put(14); cout << " " << "All of me" << endl;
                    cout << "\t>>>Si desea cambiar la cancion, por favor, pulse cualquier tecla" << endl;
                    PlaySound(TEXT("All of me1.wav"), NULL, SND_SYNC);
                    cout << "Musica actual: "; cout.put(14); cout << " " << "Move together" << endl;
                    cout << "\t>>>Si desea salir, por favor, por favor, pulse cualquier tecla" << endl;
                    cout << "\t  ";
                    PlaySound(TEXT("Move together1.wav"), NULL, SND_SYNC);
                    system("Pause");
                }
                else if (n == 3) {
                    cout << "Musica actual: "; cout.put(14); cout << " " << "Hold On" << endl;
                    cout << "\t>>>Si desea cambiar la cancion, por favor, pulse cualquier tecla" << endl;
                    PlaySound(TEXT("Hold On1.wav"), NULL, SND_SYNC);
                    cout << "Musica actual: "; cout.put(14); cout << " " << "Angel with a Shotgun" << endl;
                    cout << "\t>>>Si desea cambiar la cancion, por favor, pulse cualquier tecla" << endl;
                    PlaySound(TEXT("Angel with a Shotgun1.wav"), NULL, SND_SYNC);
                    cout << "Musica actual: "; cout.put(14); cout << " " << "musica5" << endl;
                    cout << "\t>>>Si desea salir, por favor, pulse cualquier tecla" << endl;
                    cout << "\t  ";
                    PlaySound(TEXT("musica5_1.wav"), NULL, SND_SYNC);
                    system("Pause");
                }
                /*else if (n == 4) {
                    cout << "Musica actual: "; cout.put(14); cout << " " << "Move together" << endl;
                    cout << "\t>>>Si desea cambiar la cancion, por favor, pulse cualquier tecla" << endl;
                    PlaySound(TEXT("Move together1.wav"), NULL, SND_SYNC);
                    cout << "Musica actual: "; cout.put(14); cout << " " << "Human" << endl;
                    cout << "\t>>>Si desea cambiar la cancion, por favor, pulse cualquier tecla" << endl;
                    PlaySound(TEXT("Human1.wav"), NULL, SND_SYNC);
                    cout << "Musica actual: "; cout.put(14); cout << " " << "Hold On" << endl;
                    cout << "\t>>>Si desea cambiar la cancion, por favor, pulse cualquier tecla" << endl;
                    PlaySound(TEXT("Hold On1.wav"), NULL, SND_SYNC);
                    cout << "Musica actual: "; cout.put(14); cout << " " << "musica5" << endl;
                    cout << "\t>>>Si desea salir, por favor, pulse cualquier tecla" << endl;
                    cout << "\t  ";
                    PlaySound(TEXT("musica5_1.wav"), NULL, SND_SYNC);
                    system("Pause");
                }*/
            }
            break;
        case 7:
            RetornoTabla();
            break;
      }
    }
    cout << "FIN DEL PROGRAMA PLAYMUSIC" << endl;
    system("pause");

    _getch();

	}
