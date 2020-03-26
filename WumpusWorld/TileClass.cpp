#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "TileClass.h"

void Tile::SetTilePits() {
	
	int rand_num = (rand() % 2) + 1;
	

	switch (rand_num) {
	case 1:
		type = 'P';
		break;
	case 2:
		type = 'N';
		break;
	}
}

