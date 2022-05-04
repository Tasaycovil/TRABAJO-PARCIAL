#pragma once
#include <iostream>
#include <vector>
using namespace std;

void ordAgregar(vector<string>& listMusic, vector<string>& musicFound)
{
    for (unsigned int i = 0; i < listMusic.size() - 1; i++)
    {
        for (unsigned int k = i + 1; k < listMusic.size(); k++)
        {
            if (a[i] > a[k])
            {
                int aux = a[i];
                a[i] = musicFound[k];
                a[k] = aux;
            }
        }
    }
}