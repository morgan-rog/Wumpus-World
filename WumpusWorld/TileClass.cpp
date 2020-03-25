#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "TileClass.h"

void Tile::SetTilePits() {
	cout << "set tile pits called" << endl;
	
	int rand_num = (rand() % 2) + 1;
	
	cout << "rand num: " << rand_num << endl;

	switch (rand_num) {
	case 1:
		type = 'P';
		break;
	case 2:
		type = 'N';
		break;
	}
}

