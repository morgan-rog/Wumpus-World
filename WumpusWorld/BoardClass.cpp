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

void Board::run_game1() { //PHASE 1
	char quit = ' ';
	print_welcome_menu();

	while (toupper(quit) != 'Q') {
		reset_robot_tile();
		if (check_tile_clues()) { //returns true if robot receives wumpus smell
			if (shoot_wumpus()) {
				cout << endl;
				cout << "Robot successfully shot the wumpus!!! Collect the gold!!!" << endl; 
				cout << endl;
			}
		}
		robot->ChooseMove();
		if (check_tile_pit_or_wumpus()) {
			if (check_tile_gold()) {
				break;
			}
			board[robot->GetRow()][robot->GetCol()].SetType('~');
		}
		else {
			break;
		}
		print_board();
		
	}
}

void Board::run_game2() { //PHASE 2
	print_phase2_menu();
}

bool Board::shoot_wumpus() { //FIXME
	char choice = ' ';
	int r, c;
	char face;

	while (toupper(choice) != 'Y' && toupper(choice) != 'N') {
		if (robot->GetArrow() < 1) {
			return false;
		}
		cout << "Use only arrow to try and shoot the Wumpus? (Y)es (N)o" << endl;
		cin >> choice;
		if (toupper(choice) == 'Y') {
			while (true) {
				cout << "Where do you want the robot to face? (S) down (W) up (D) right (A) left" << endl;
				cin >> face;
				switch (toupper(face)) {
				case 'S': //face down
				{
					r = robot->GetRow() + 1;
					c = robot->GetCol();
					if (r >= 0 && r <= 3 && c >= 0 && c <= 3) {
						if (board[r][c].GetType() == 'W') {
							board[r][c].SetType('N');
							return true;
						}
						else {
							robot->LoseArrow();
							cout << endl;
							cout << "Robot was not able to successfully shoot the Wumpus...Robot's only arrow lost" << endl;
							cout << "Good Luck!" << endl;
							cout << endl;
							return false; 
						}
					}
					else {
						return false;
					}
					break;
				}
				case 'W': //face up
				{
					r = robot->GetRow() - 1;
					c = robot->GetCol();
					if (r >= 0 && r <= 3 && c >= 0 && c <= 3) {
						if (board[r][c].GetType() == 'W') {
							board[r][c].SetType('N');
							return true;
						}
						else {
							robot->LoseArrow();
							cout << endl;
							cout << "Robot was not able to successfully shoot the Wumpus...Robot's only arrow lost" << endl;
							cout << "Good Luck!" << endl;
							cout << endl;
							return false; 
						}
					}
					else {
						return false;
					}
					break;
				}
				case 'D': //face right
				{
					r = robot->GetRow();
					c = robot->GetCol() + 1;
					if (r >= 0 && r <= 3 && c >= 0 && c <= 3) {
						if (board[r][c].GetType() == 'W') {
							board[r][c].SetType('N');
							return true;
						}
						else {
							robot->LoseArrow();
							cout << endl;
							cout << "Robot was not able to successfully shoot the Wumpus...Robot's only arrow lost" << endl;
							cout << "Good Luck!" << endl;
							cout << endl;
							return false; 
						}
					}
					else {
						return false;
					}
					break;
				}
				case 'A': //face left
				{
					r = robot->GetRow() - 1;
					c = robot->GetCol();
					if (r >= 0 && r <= 3 && c >= 0 && c <= 3) {
						if (board[r][c].GetType() == 'W') {
							board[r][c].SetType('N');
							return true;
						}
						else {
							robot->LoseArrow();
							cout << endl;
							cout << "Robot was not able to successfully shoot the Wumpus...Robot's only arrow lost" << endl;
							cout << "Good Luck!" << endl;
							cout << endl;
							return false; 
						}
					}
					else {
						return false;
					}
					break;
				}
				default:
				{
					cout << "Please enter valid facing" << endl;
					break;
				}
				}
			}

		}
		else if (toupper(choice) == 'N') {
			return false;
		}
		else {
			cout << "Please enter a valid choice" << endl;
		}
	}
	return false;
}

bool Board::check_tile_pit_or_wumpus() {
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

bool Board::check_tile_gold() {
	if (board[robot->GetRow()][robot->GetCol()].GetType() == 'G') {
		cout << "Robot collected gold! Moving on to phase 2..." << endl;
		return true;
	}
	return false;
}

bool Board::check_tile_clues() {
	bool wumpus = false;
	cout << "Checking for clues..." << endl;
	int r = robot->GetRow(), c = robot->GetCol() - 1; //left square
	int r2 = robot->GetRow(), c2 = robot->GetCol() + 1; //right square
	int r3 = robot->GetRow() - 1, c3 = robot->GetCol(); //upper square
	int r4 = robot->GetRow() + 1, c4 = robot->GetCol(); //lower square

	if (r >= 0 && r <= 3 && c >= 0 && c <= 3) { //left square test
		switch (board[r][c].GetType()) {
		case 'W':
		{
			cout << "Robot: I smell a horrible smell..." << endl;
			wumpus = true;
			break;
		}
		case 'G':
		{
			cout << "Robot: I see glitter..." << endl;
			break;
		}
		case 'P':
		{
			cout << "Robot: I feel a breeze..." << endl;
			break;
		}
		}
	}
	if (r2 >= 0 && r2 <= 3 && c2 >= 0 && c2 <= 3) { //right square test
		switch (board[r2][c2].GetType()) {
		case 'W':
		{
			cout << "Robot: I smell a horrible smell..." << endl;
			wumpus = true;
			break;
		}
		case 'G':
		{
			cout << "Robot: I see glitter..." << endl;
			break;
		}
		case 'P':
		{
			cout << "Robot: I feel a breeze..." << endl;
			break;
		}
		}
	}
	if (r3 >= 0 && r3 <= 3 && c3 >= 0 && c3 <= 3) { //upper square test
		switch (board[r3][c3].GetType()) {
		case 'W':
		{
			cout << "Robot: I smell a horrible smell..." << endl;
			wumpus = true;
			break;
		}
		case 'G':
		{
			cout << "Robot: I see glitter..." << endl;
			break;
		}
		case 'P':
		{
			cout << "Robot: I feel a breeze..." << endl;
			break;
		}
		}
	}
	if (r4 >= 0 && r4 <= 3 && c4 >= 0 && c4 <= 3) { //lower square test
		switch (board[r4][c4].GetType()) {
		case 'W':
		{
			cout << "Robot: I smell a horrible smell..." << endl;
			wumpus = true;
			break;
		}
		case 'G':
		{
			cout << "Robot: I see glitter..." << endl;
			break;
		}
		case 'P':
		{
			cout << "Robot: I feel a breeze..." << endl;
			break;
		}
		}
	}
	return wumpus;
}

void Board::print_welcome_menu() {
	cout << endl;
	cout << "Welcome to Wumpus World!" << endl;
	cout << "You are the robot (~)... avoid the Wumpus and pits and collect the gold!" << endl;
	cout << endl;
}

void Board::print_phase2_menu() {
	cout << endl;
	cout << "Welcome to Wumpus World Phase 2!" << endl;
	cout << "Make it back to the starting position and you win!!" << endl;
	cout << endl;
}

void Board::print_board() {
	cout << "unhidden board" << endl;
	for (int i = 0; i < 4; ++i) { //unhidden board
		for (int j = 0; j < 4; ++j) {
			cout << " | " << board[i][j].GetType() << " | ";
		}
		cout << endl;
	}
	cout << "hidden board" << endl;
	for (int i = 0; i < 4; ++i) { //hidden board
		for (int j = 0; j < 4; ++j) {
			if (board[i][j].GetType() == '~') {
				cout << " | " << board[i][j].GetType() << " | ";
			}
			else {
				cout << " | " << board[i][j].GetHiddenType() << " | ";
			}
		}
		cout << endl;
	}
}