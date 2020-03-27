#include <iostream>
#include <string>
#include <cstdlib>
#include "TileClass.h"
#include "BoardClass.h"
using namespace std;


int main() {
	Board* the_board;

	the_board = new Board();

	the_board->print_board();
	
	the_board->run_game1(); //phase 1

	if (the_board->check_robot_gold()) { //phase 2
        the_board->run_game2();
	}

    return 0;
}