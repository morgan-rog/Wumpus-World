#include <iostream>
#include "RobotClass.h"

using namespace std;

void Robot::ResetRobot() {
	arrow = 1;
	gold = false;
	ruby = false;
	ladder = false;
	glitter = false;
	red_glitter = false;
	horrible_smell = false;
	breeze = false;
	gameover = false;
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
				cout << "BOUNCE!" << endl;
				cout << "Robot hit a wall!" << endl;
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
				cout << "BOUNCE!" << endl;
				cout << "Robot hit a wall!" << endl;
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
				cout << "BOUNCE!" << endl;
				cout << "Robot hit a wall!" << endl;
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
				cout << "BOUNCE!" << endl;
				cout << "Robot hit a wall!" << endl;
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