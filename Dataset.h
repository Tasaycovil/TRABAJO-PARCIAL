#pragma once
#pragma comment (lib, "winmm.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <string>
#include "Lista.h"
#include "Agregar.h"
#include "Reproduccion.h"
using namespace std;
void Datasetcancion()
{
    int n;
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
