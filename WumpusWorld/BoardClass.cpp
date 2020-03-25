#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "BoardClass.h"
#include "TileClass.h"
using namespace std;

void Board::create_board() { //sets wumpus and gold
	cout << "create board called" << endl;
	int rand_int1;
	int rand_int2;
	rand_int1 = (rand() % 4);
	rand_int2 = (rand() % 4);
	if (rand_int1 == 0 && rand_int2 == 0) {
		board[3][3].SetGold();
	}
	else {
		board[rand_int1][rand_int2].SetGold();
	}
	rand_int1 = (rand() % 4);
	rand_int2 = (rand() % 4);
	if (rand_int1 == 0 && rand_int2 == 0) {
		board[2][2].SetWumpus();
	}
	else {
		board[rand_int1][rand_int2].SetWumpus();
	}
	board[2][0].SetType('N'); //enforces path on board
}

void Board::run_game() {
	//FIXME
}

void Board::print_board() {
	cout << board[0][0].GetType() << " | " << board[0][1].GetType() << " | " << board[0][2].GetType() << " | " << board[0][3].GetType() << endl;
	cout << board[1][0].GetType() << " | " << board[1][1].GetType() << " | " << board[1][2].GetType() << " | " << board[1][3].GetType() << endl;
	cout << board[2][0].GetType() << " | " << board[2][1].GetType() << " | " << board[2][2].GetType() << " | " << board[2][3].GetType() << endl;
	cout << board[3][0].GetType() << " | " << board[3][1].GetType() << " | " << board[3][2].GetType() << " | " << board[3][3].GetType() << endl;
}