#include <iostream>
#include "RobotClass.h"

using namespace std;

Robot::Robot() {
	row = 0;
	col = 0;
	arrow = 1;
	gold = false;
}

void Robot::ChooseMove() {
	int r, c;
	char choice;
	bool success = false;

	while (!success) {
		cout << "Where's your next move? (S) down (W) up (D) right (A) left" << endl;
		cin >> choice;

		switch (toupper(choice)) {
		case 'S':
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
		case 'W':
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
		case 'D':
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
		case 'A':
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