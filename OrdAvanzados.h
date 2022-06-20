#pragma once
#include <iostream>
#include <fstream>
using namespace std;
//funcion del pivote y intercambio
int particion(int* A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}
//Quicksort
//funcion donde se devuelve el indice del pivote
void quicksort(int* A, int p, int r) {
	int q;
	if (p < r) {
		q = particion(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}
//Quickselect
//para numero elementos kesimo
int quickselect(int* A, int p, int r, int k) {
	if (p == r) return A[p];
	int q = particion(A, p, r);
	int l = q - p + 1;
	if (k == l)
		return A[q];
	else if (k < 1)
		return quickselect(A, p, q - 1, k);
	else
		return quickselect(A, q + 1, r, k - l);

}