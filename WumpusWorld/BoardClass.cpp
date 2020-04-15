#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "BoardClass.h"
#include "TileClass.h"
using namespace std;

void Board::create_board() { 
	set_empty_spaces();
	set_ladder();
	set_pit_spaces(); //set pit spaces
	set_wumpus_and_gold(); //set wumpus and gold
	board[robot->GetRow()][robot->GetCol()].SetRobot();

}

void Board::set_empty_spaces() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j){
			board[i][j].SetEmpty();
			
		}
	}
}

void Board::set_ladder() {
	//FIXME: search algorithm
	srand(time(0));
	int rand_col, rand_row;
	while (true) {
		rand_col = rand() % 4;
		rand_row = rand() % 4;
		if (rand_row == 0 && rand_col == 0) {
			continue;
		}
		else {
			board[rand_row][rand_col].SetLadder();
			break;
		}
	}
}

void Board::set_pit_spaces() {
	srand(time(0));
	int rand_int;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			while (true) {
				rand_int = (rand() % 3);
				if (rand_int == 1 && board[i][j].GetType() == 'L') {
					continue;
				}
				else if (rand_int == 1 && board[i][j].GetType() != 'L') {
					board[i][j].SetPit();
				}
				break;
			}
		}
	}
}

void Board::set_wumpus_and_gold() {
	srand(time(0));
	int rand_chance = rand() % 2;//10 percent chance gold is ruby
	int rand_int1_gold, rand_int1_wump;
	int rand_int2_gold, rand_int2_wump;
	while (true) {
		rand_int1_gold = (rand() % 4); //set gold tile
		rand_int2_gold = (rand() % 4);
		if (rand_chance == 1) { //RUBY
			if ((rand_int1_gold == robot->GetRow() && rand_int2_gold == robot->GetCol()) && board[3][3].GetType() != 'L') {
				board[3][3].SetRuby();
				break;
			}
			else if (board[rand_int1_gold][rand_int2_gold].GetType() != 'L') {
				board[rand_int1_gold][rand_int2_gold].SetRuby();
				break;
			}
			else {
				continue;
			}
		}
		else { //GOLD
			if ((rand_int1_gold == robot->GetRow() && rand_int2_gold == robot->GetCol()) && board[3][3].GetType() != 'L' ) {
				board[3][3].SetGold();
				break;
			}
			else if(board[rand_int1_gold][rand_int2_gold].GetType() != 'L'){
				board[rand_int1_gold][rand_int2_gold].SetGold();
				break;
			}
			else {
				continue;
			}
		}
	}
	while (true) {
		rand_int1_wump = (rand() % 4); //set wumpus tile
		rand_int2_wump = (rand() % 4);
		if ((rand_int1_wump == robot->GetRow() && rand_int2_wump == robot->GetCol()) && board[2][2].GetType() != 'L') {
			board[2][2].SetWumpus();
			break;
		}
		else if ((board[rand_int1_wump][rand_int2_wump].GetType() != 'L') && ((rand_int1_wump != rand_int1_gold) && (rand_int2_wump != rand_int2_gold))) {
			board[rand_int1_wump][rand_int2_wump].SetWumpus();
			break;
		}
		else {
			continue;
		}
	}
}

bool Board::wumpus_move() {
	srand(time(0));
	int count = 0;
	int row, col;
	for (int i = 0; i < 4; ++i) { //find wumpus location
		for (int j = 0; j < 4; ++j) {
			if (board[i][j].GetType() == 'W') {
				count += 1;
				row = i;
				col = j;
			}
		}
	}
	if (count == 0) {
		return false;
	}
	int rand_num = (rand() % 4) + 1;
	cout << "Wumpus rand num: " << rand_num << endl;
	switch (rand_num) {
	case 1:
	{
		int r = row, c = col - 1; //left square
		if (r >= 0 && r <= 3 && c >= 0 && c <= 3) { //left square test
			if (board[r][c].GetType() == '~') {
				board[r][c].SetWumpus();
				board[row][col].SetEmpty();
				cout << "WUMPUS ATE THE ROBOT! (minus 50 points)" << endl;
				cout << "GAMEOVER" << endl;
				robot->LoseWumpusPoints();
				cout << "Robot Points: " << robot->GetPoints() << endl; //output points
                return true;
			}
			else if (board[r][c].GetType() == 'N'){
				board[r][c].SetWumpus();
				board[row][col].SetEmpty();
				return false;
			}
		}
		break;
	}
	case 2:
	{
		int r2 = row, c2 = col + 1; //right square
		if (r2 >= 0 && r2 <= 3 && c2 >= 0 && c2 <= 3) { //right square test
			if (board[r2][c2].GetType() == '~') {
				board[r2][c2].SetWumpus();
				board[row][col].SetEmpty();
				cout << "WUMPUS ATE THE ROBOT! (minus 50 points)" << endl;
				cout << "GAMEOVER" << endl;
				robot->LoseWumpusPoints();
				cout << "Robot Points: " << robot->GetPoints() << endl; //output points
				return true;
			}
			else if (board[r2][c2].GetType() == 'N') {
				board[r2][c2].SetWumpus();
				board[row][col].SetEmpty();
				return false;
			}
		}

		break;
	}
	case 3:
	{
		int r3 = row - 1, c3 = col; //upper square
		if (r3 >= 0 && r3 <= 3 && c3 >= 0 && c3 <= 3) { //upper square test
			if (board[r3][c3].GetType() == '~') {
				board[r3][c3].SetWumpus();
				board[row][col].SetEmpty();
				cout << "WUMPUS ATE THE ROBOT! (minus 50 points)" << endl;
				cout << "GAMEOVER" << endl;
				robot->LoseWumpusPoints();
				cout << "Robot Points: " << robot->GetPoints() << endl; //output points
				return true;
			}
			else if (board[r3][c3].GetType() == 'N') {
				board[r3][c3].SetWumpus();
				board[row][col].SetEmpty();
				return false;
			}
		}

		break;
	}
	case 4:
	{
		int r4 = row + 1, c4 = col; //lower square
		if (r4 >= 0 && r4 <= 3 && c4 >= 0 && c4 <= 3) { //lower square test
			if (board[r4][c4].GetType() == '~') {
				board[r4][c4].SetWumpus();
				board[row][col].SetEmpty();
				cout << "WUMPUS ATE THE ROBOT! (minus 50 points)" << endl;
				cout << "GAMEOVER" << endl;
				robot->LoseWumpusPoints();
				cout << "Robot Points: " << robot->GetPoints() << endl; //output points
				return true;
			}
			else if (board[r4][c4].GetType() == 'N') {
				board[r4][c4].SetWumpus();
				board[row][col].SetEmpty();
				return false;
			}
		}

		break;
	}
	}
	return false;

}

void Board::run_game1() { //PHASE 1

	while (true) {
		print_unhidden_board();
		reset_robot_tile();
		
		if (check_tile_clues()) { //returns true if robot receives wumpus smell
			if (shoot_wumpus()) { //returns true if robot shot the wumpus
				cout << endl;
				cout << "Robot successfully shot the wumpus!!!" << endl; 
				cout << endl;
			}
		}
		
		robot->ChooseMove(); //robot move
		
		if (check_tile_pit_or_wumpus()) { //returns true if no pit or wumpus
			if (check_ladder()) { //returns true if tile is ladder
				break;
			}
			if (check_tile_gold() || check_tile_ruby()) {
				cout << "Make it to the ladder to continue on to the next cave..." << endl;
			}
			board[robot->GetRow()][robot->GetCol()].SetRobot();
		}
		else {
			break;
		}
		if (wumpus_move()) { //wumpus move - returns true if wumpus eats robot
			robot->SetGameOver(true);
			break;
		}
		print_hidden_board();
		
	}
}

bool Board::shoot_wumpus() { 
	char choice = ' ';
	int r, c;
	char face;
	cout << endl;

	while (toupper(choice) != 'N') {
		if (robot->GetArrow() < 1) {
			return false;
		}
		cout << "Use only arrow to try and shoot the Wumpus? Press N for No, any key for Yes" << endl;
		cin >> choice;
		if (toupper(choice) != 'N') {
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
							board[r][c].SetEmpty();
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
							board[r][c].SetEmpty();
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
							board[r][c].SetEmpty();
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
							board[r][c].SetEmpty();
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
	}
	return false;
}

bool Board::check_tile_pit_or_wumpus() {
	if (board[robot->GetRow()][robot->GetCol()].GetType() == 'P') {
		cout << endl;
		cout << "Robot fell into a pit! (minus 25 points)" << endl;
		cout << "GAMEOVER" << endl;
		robot->SetGameOver(true);
		robot->LosePitPoints(); //lose 25 points
		cout << "Robot Points: " << robot->GetPoints() << endl; //output points
		return false;
	}
	else if (board[robot->GetRow()][robot->GetCol()].GetType() == 'W') {
		cout << endl;
		cout << "Robot was eaten by the Wumpus! (minus 50 points)" << endl;
		cout << "GAMEOVER" << endl;
		robot->SetGameOver(true);
		robot->LoseWumpusPoints(); //lose 50 points
		cout << "Robot Points: " << robot->GetPoints() << endl; //output points
		return false;
	}
	return true;
}

bool Board::check_tile_gold() {
	if (board[robot->GetRow()][robot->GetCol()].GetType() == 'G') {
		cout << endl;
		cout << "Robot collected the gold!" << endl;
		robot->SetGoldTrue();
		robot->AddGoldPoints(); //add gold points to total points (50)
		cout << "Robot Points: " << robot->GetPoints() << endl; //output points
		return true;
	}
	return false;
}

bool Board::check_tile_ruby() {
	if (board[robot->GetRow()][robot->GetCol()].GetType() == 'R') {
		cout << endl;
		cout << "Robot collected the ruby!" << endl;
		robot->SetRubyTrue();
		robot->AddRubyPoints(); //add ruby points to total points (100)
		cout << "Robot Points: " << robot->GetPoints() << endl; //output points
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
			robot->SetSmell(true);
			wumpus = true;
			break;
		}
		case 'G':
		{
			robot->SetGlitter(true);
			break;
		}
		case 'R':
		{
			robot->SetRedGlitter(true);
			break;
		}
		case 'P':
		{
			robot->SetBreeze(true);
			break;
		}
		}
	}
	if (r2 >= 0 && r2 <= 3 && c2 >= 0 && c2 <= 3) { //right square test
		switch (board[r2][c2].GetType()) {
		case 'W':
		{
			robot->SetSmell(true);
			wumpus = true;
			break;
		}
		case 'G':
		{
			robot->SetGlitter(true);
			break;
		}
		case 'R':
		{
			robot->SetRedGlitter(true);
			break;
		}
		case 'P':
		{
			robot->SetBreeze(true);
			break;
		}
		}
	}
	if (r3 >= 0 && r3 <= 3 && c3 >= 0 && c3 <= 3) { //upper square test
		switch (board[r3][c3].GetType()) {
		case 'W':
		{
			robot->SetSmell(true);
			wumpus = true;
			break;
		}
		case 'G':
		{
			robot->SetGlitter(true);
			break;
		}
		case 'R':
		{
			robot->SetRedGlitter(true);
			break;
		}
		case 'P':
		{
			robot->SetBreeze(true);
			break;
		}
		}
	}
	if (r4 >= 0 && r4 <= 3 && c4 >= 0 && c4 <= 3) { //lower square test
		switch (board[r4][c4].GetType()) {
		case 'W':
		{
			robot->SetSmell(true);
			wumpus = true;
			break;
		}
		case 'G':
		{
			robot->SetGlitter(true);
			break;
		}
		case 'R':
		{
			robot->SetRedGlitter(true);
			break;
		}
		case 'P':
		{
			robot->SetBreeze(true);
			break;
		}
		}
	}
	if (robot->GetSmell()) {
		cout << "Robot: I smell a horrible smell..." << endl;
	}
	if (robot->GetGlitter()) {
		cout << "Robot: I see glitter..." << endl;
	}
	if (robot->GetRedGlitter()) {
		cout << "Robot: I see RED glitter..." << endl;
	}
	if (robot->GetBreeze()) {
		cout << "Robot: I feel a breeze..." << endl;
	}
	robot->SetSmell(false); //reset senses
	robot->SetGlitter(false);
	robot->SetRedGlitter(false);
	robot->SetBreeze(false);
	return wumpus;
}

bool Board::check_ladder() { 
	if (board[robot->GetRow()][robot->GetCol()].GetType() == 'L') {
		cout << "Robot made it to the ladder - Robot has " << robot->GetPoints() << " points" << endl;
		cout << "Onto the next cave..." << endl;
		robot->SetLadderTrue();
		return true;
	}
	return false;
}


void Board::print_welcome_menu() {
	cout << endl;
	cout << "Welcome to Wumpus World!" << endl;
	cout << "You are the robot (~)... shoot the Wumpus, avoid the pits, and collect the loot!" << endl;
	cout << endl;
}

void Board::print_phase2_menu() {
	cout << endl;
	cout << "Wumpus World Phase 2!" << endl;
	cout << "You successfully collected the gold! Make it back to the ladder and you win!!" << endl;
	cout << endl;
}

void Board::print_hidden_board() {
    for (int i = 0; i < 4; ++i) { //hidden board
		for (int j = 0; j < 4; ++j) {
			if (board[i][j].GetType() == '~') { //outputs robot
				cout << " | " << board[i][j].GetType() << " | ";
			}
			else if (board[i][j].GetType() == 'L') { //outputs ladder during phase 2
				cout << " | " << board[i][j].GetType() << " | ";
			}
			else {
				cout << " | " << board[i][j].GetHiddenType() << " | ";
			}
		}
		cout << endl;
	}
}
void Board::print_unhidden_board() {
	cout << endl;
	cout << "Unhidden board:" << endl;
	for (int i = 0; i < 4; ++i) { //unhidden board
		for (int j = 0; j < 4; ++j) {
			cout << " | " << board[i][j].GetType() << " | ";
		}
		cout << endl;
	}
	cout << endl;
	
}

void Board::reset_game() {
	create_board();
	robot->ResetRobot();
}

void Board::save_game() {
	ofstream file;
	string name;
	file.open("WumpusScores.txt");
	if (!file.is_open()) {
		cout << "Could not open score file..." << endl;
	}
	else {
		file << robot->GetPoints() << endl;
		
	}
	file.close();
}

void Board::update_robot_points() {
	ifstream file;
	int x;
	file.open("WumpusScores.txt");
	if (!file.is_open()) {
		cout << "Could not open score file..." << endl;
	}
	else {
		file >> x;
		robot->SetTotalPoints(x);
	}
}