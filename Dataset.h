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
#include "Reproduccion.h"
using namespace std;
void DatasetCancion(vector<string>& listMusic)
{
    int i;
    if (i == 1) {
        for (unsigned int i = 0; i < 1; i++)
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
    else if (i == 2) {
        for (unsigned int i = 0; i < 2; i++)
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
    /*int i;
        fflush(stdin);
        if (i == 1)
            system("cd.. & dir *.wav /b /s > Debug\\Human.wav");
            //cabeza = insertar_nodo(1, "Human", "cd.. & dir * .wav / b / s > Debug\\Human.wav", cabeza);
        wstring temp = wstring(listMusic[i].begin(), listMusic[i].end());
        LPCWSTR wideString = temp.c_str();
        sndPlaySound("cd.. & dir *.wav /b /s > Debug\\Human.wav",0);
        /*else if (i == 2) {
            cabeza = insertar_nodo(1, "Human", "cd.. & dir * .wav / b / s > Debug\\Human.wav", cabeza);
            cabeza = insertar_nodo(2, "All of me", "cd.. & dir * .wav / b / s > Debug\\All of me.wav", cabeza);
            cout << "Pista actual: "; cout.put(14); cout << " " << listMusic[i] << endl;
            PlaySound(wideString, NULL, SND_FILENAME | SND_ASYNC);
        }
        /*else if (i == 3) {
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
        PlaySound(NULL, 0, 0);*/
}