#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<string>&musicFound, vector<string>&listMusic) {
	if (musicFound < listMusic){
		
	}
	int key, j;

	for (int i = 1; i < n; i++) {

		key = v[i];

		j = i - 1;

		while (j >= 0 && v[j] > key) {

			v[j + 1] = v[j];

			j = j - 1;

		}

		v[j + 1] = key;

	}

}