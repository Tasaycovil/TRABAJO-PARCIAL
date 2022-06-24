#pragma once
using namespace std;
//funcion del pivote y intercambio
int particion(vector<string>& musicFound, int p, int r) {
    string x = musicFound[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (musicFound[j] <= x) {
            i++;
            swap(musicFound[i], musicFound[j]);
        }
    }
    swap(musicFound[i + 1], musicFound[r]);
    return i + 1;
}
//Quicksort
//funcion donde se devuelve el indice del pivote
void quicksort(vector<string>& musicFound, int p, int r) {
    int q;
    if (p < r) {
        q = particion(musicFound, p, r);
        quicksort(musicFound, p, q - 1);
        quicksort(musicFound, q + 1, r);
    }
}

//Quickselect}
//para numero elementos kesimo
int quickselect(vector<string>& musicFound, int p, int r, int k) {
    //  if (p == r) 
   // return musicFound[p];//indice del pivote
    int q = particion(musicFound, p, r);
    int l = q - p + 1;// sub lista para el kesimo elemento
    if (k == l)
     //return musicFound[q];
     //else if (k < 1)
        return quickselect(musicFound, p, q - 1, k);
    else
        return quickselect(musicFound, q + 1, r, k - l);
}
