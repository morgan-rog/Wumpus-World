#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "TileClass.h"
#include "BoardClass.h"
using namespace std;


int main() {
	Board* the_board;

	the_board = new Board();

	the_board->print_board();

    return 0;
}