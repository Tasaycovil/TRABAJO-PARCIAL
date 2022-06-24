#pragma once
#include <iostream>
#include <conio.h>
#include "HashEntidad.h"

using namespace std;

//Tamaño de la tabla 
const int tamano_tablah = 1000;

class HashTabla {
private:
	HashEntidad** tabla;

public:
	//Funcion que delimita el tamaño de la tabla 
	HashTabla() {
		tabla = new HashEntidad * [tamano_tablah];
		for (int i = 0; i < tamano_tablah; i++) {
			tabla[i] = NULL;
		}
	}

	int FuncionHash(int key) {
		return key % tamano_tablah;
	}

	void insertar(int key, int value) {
		int h = FuncionHash(key);
		while (tabla[h] != NULL && tabla[h]->key != key) {
			h = FuncionHash(h + 1);
		}
		if (tabla[h] != NULL)
			delete tabla[h];
		tabla[h] = new HashEntidad(key, value);
	}
	int BusquedaKey(int key) {
		int h = FuncionHash(key);
		while (tabla[h] != NULL && tabla[h]->key != key) {
			h = FuncionHash(h + 1);
		}
		if (tabla[h] == NULL)
			return -1;
		else
			return tabla[h]->value;
	}

	void Remover(int key) {
		int h = FuncionHash(key);
		while (tabla[h] != NULL) {
			if (tabla[h]->key == key)
				break;
			h = FuncionHash(h + 1);
		}
		if (tabla[h] == NULL) {
			cout << "No existe ningun elemento con esta key" << key << endl;
			return;
		}
		else
		{
			delete tabla[h];
		}
		cout << "Elemento Borrado" << endl;
	}

	~HashTabla() {
		for (int i = 0; i < tamano_tablah; i++) {
			if (tabla[i] != nullptr)
				delete tabla[i];
		}
		delete[] tabla;
	}
};

void RetornoTabla() {
	HashTabla hash;
	int key, value;
	int opcion;
	while (1) {
		cout << "\t\t|_____   PLAYMUSIC    _____|" << endl;
		cout << "\t\t|__  Insercion por HASH  __|" << endl;
		cout << "\t\t|   1.Insertar Cancion:    |" << endl;
		cout << "\t\t|   2.Buscar Cancion:      |" << endl;
		cout << "\t\t|   3.Borrar Cancion:      |" << endl;
		cout << "\t\t|__________________________|" << endl;
		cout << "\t\t|   4.Salir                |" << endl;
		cout << "\t\t|__________________________|" << endl;
		cout << "\t\t\tIngrese una opcion: ";

		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Insertar Cancion :";
			cin >> value;
			cout << "Ingrese key de cancion:";
			cin >> key;
			hash.insertar(key, value);
			_getch();
			break;
		case 2:
			cout << "Buscar cancion por key: ";
			cin >> key;
			if (hash.BusquedaKey(key) == -1) {
				cout << "No existe cancion con esta llave" << key << endl;
				_getch();
				continue;
			}
			else {
				cout << "Cancion con esta llave" << key << ":";
				cout << hash.BusquedaKey(key) << endl;
				_getch();
			}
			break;
		case 3:
			cout << "Ingrese key para eliminar :";
			cin >> key;
			hash.Remover(key);
			break;
		case 4:
			exit(1);
		default:
			cout << "\n Por favor ingrese una opcion valida\n";
			system("cls");
		}
		system("cls");
	}
}