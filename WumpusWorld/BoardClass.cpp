#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "BoardClass.h"
#include "TileClass.h"
using namespace std;

void Board::create_board() { //sets wumpus and gold
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
	board[robot->GetRow()][robot->GetCol()].SetType('~');
}

void Board::run_game1() {
	char quit = ' ';
	print_welcome_menu();

	while (toupper(quit) != 'Q') {
		reset_robot_tile();
		robot->ChooseMove();
		if (check_tile()) {
			cout << "Robot row: " << robot->GetRow() << endl;
			cout << "Robot col: " << robot->GetCol() << endl;
			board[robot->GetRow()][robot->GetCol()].SetType('~');
		}
		else {
			break;
		}
		print_board();
		
	}
}

void Board::run_game2() {
	//FIXME
}

bool Board::check_tile() {
	if (board[robot->GetRow()][robot->GetCol()].GetType() == 'P') {
		cout << "Robot fell into a pit!" << endl;
		cout << "GAMEOVER" << endl;
		return false;
	}
	else if (board[robot->GetRow()][robot->GetCol()].GetType() == 'W') {
		cout << "Robot was eaten by the Wumpus!" << endl;
		cout << "GAMEOVER" << endl;
		return false;
	}
	return true;
}

void Board::print_welcome_menu() {
	cout << "Welcome to Wumpus World!" << endl;
	cout << "You are the robot (~)... avoid the Wumpus and pits and retrieve the gold!" << endl;
}

void Board::print_board() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << " | " << board[i][j].GetType() << " | ";
		}
		cout << endl;
	}
}