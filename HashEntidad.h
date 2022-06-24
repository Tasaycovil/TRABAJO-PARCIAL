#pragma once
class HashEntidad {
public:
	int key;
	int value;
	HashEntidad(int key, int value) {
		this->key = key;
		this->value = value;
	}
};