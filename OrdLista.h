#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void ordLista(vector<string>&musicFound , int m)
{
    for (unsigned int i = 0; i < m - 1; i++)
    {
        for (unsigned int k = i + 1; k < m; k++)
        {
            if (a[i] > a[k])
            {
                int aux = a[i];
                a[i] = a[k];
                a[k] = aux;
            }
        }
    }
}