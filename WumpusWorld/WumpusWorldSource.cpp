#include <iostream>
#include <string>
#include <cstdlib>
#include "TileClass.h"
#include "BoardClass.h"
using namespace std;


int main() {
	char choice = ' ';
	char choice2;
	Board* the_board;

	the_board = new Board();

	the_board->print_hidden_board();
	the_board->print_welcome_menu();

	cout << "Continue playing from last saved game? Press Y for yes" << endl;
	cin >> choice2;

	if (toupper(choice2) == 'Y') {
		the_board->update_robot_points();
		cout << endl;
	}

	while (toupper(choice) != 'N') {
		the_board->run_game1(); //phase 1

		if (the_board->check_robot_ladder()) {
			cout << "Continue onto the next cave? Press N for no" << endl;
			cin >> choice;
			if (toupper(choice) == 'N') {
				cout << endl;
				cout << "Saving game..." << endl;
				the_board->save_game();
				cout << endl;
				cout << "Thanks for playing!" << endl;
			}
			the_board->reset_game();
		}
		else if (the_board->check_gameover()) {
			cout << endl;
			cout << "Saving game..." << endl;
			the_board->save_game();
			break;
		}
	}

	/*if (the_board->check_robot_gold() ) { //phase 2
        the_board->run_game2();
	}
	*/
	the_board->print_unhidden_board();

    return 0;
}