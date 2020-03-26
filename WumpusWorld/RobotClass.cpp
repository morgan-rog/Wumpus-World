#include <iostream>
#include "RobotClass.h"

using namespace std;

Robot::Robot() {
	row = 0;
	col = 0;
}

void Robot::ChooseMove() {
	int r, c;
	char choice;
	bool success = false;

	while (!success) {
		cout << "Where's your next move? (D)own (U)p (R)ight (L)eft" << endl;
		cin >> choice;

		switch (toupper(choice)) {
		case 'D':
		{
			r = row + 1;
			if (r > 3 || r < 0) {
				cout << "Invalid move - cannot move down" << endl;
			}
			else {
				row = r;
				success = true;
			}
			break;
		}
		case 'U':
		{
			r = row - 1;
			if (r > 3 || r < 0) {
				cout << "Invalid move - cannot move up" << endl;
			}
			else {
				row = r;
				success = true;
			}
			break;
		}
		case 'R':
		{
			c = col + 1;
			if (c > 3 || c < 0) {
				cout << "Invalid move - cannot move right" << endl;
			}
			else {
				col = c;
				success = true;
			}
			break;
		}
		case 'L':
		{
			c = col - 1;
			if (c > 3 || c < 0) {
				cout << "Invalid move - cannot move left" << endl;
			}
			else {
				col = c;
				success = true;
			}
			break;
		}
		default:
		{
			cout << "Please make a valid choice" << endl;
			break;
		}
		}
		
	}
}