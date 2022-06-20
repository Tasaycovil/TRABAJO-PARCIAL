#pragma once
#include <iostream>
#include <vector>
using namespace std;

void ordAgregar(vector<string>& listMusic, vector<string>& MusicFound)
{
    for (unsigned int i = 0; i < listMusic.size() - 1; i++)
    {
        for (unsigned int k = i + 1; k < listMusic.size(); k++)
        {
            if (MusicFound[i] > MusicFound[k])
            {
                string aux = MusicFound[i];
                MusicFound[i] = MusicFound[k];
                MusicFound[k] = aux;

            }
        }
    }
}
