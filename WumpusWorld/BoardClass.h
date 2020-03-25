#pragma once
#ifndef BOARDCLASS_H
#define BOARDCLASS_H
#include "TileClass.h"

class Board {
public:
	Board() { create_board(); }
	void create_board(); //sets wumpus and gold
	void run_game();
	void print_board();

private:
	Tile board[4][4];


};
#endif BOARDCLASS_H