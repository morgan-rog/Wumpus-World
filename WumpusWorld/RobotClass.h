#pragma once
#ifndef ROBOTCLASS_H
#define ROBOTCLASS_H
#include <iostream>
using namespace std;

class Robot {
public:
	Robot();
	void SetRow(int r) { row = r; }
	void SetCol(int c) { col = c; }
	int GetRow() { return row; }
	int GetCol() { return col; }
	int GetArrow() { return arrow; }
	void LoseArrow() { arrow -= 1; }
	void ChooseMove();
	void SetGoldTrue() { gold = true; }
	bool GetGold() { return gold; }
	bool GetGlitter() { return glitter; }
	bool GetSmell() { return horrible_smell; }
	bool GetBreeze() { return breeze; }
	void SetGlitter(bool x) { glitter = x; }
	void SetSmell(bool x) { horrible_smell = x; }
	void SetBreeze(bool x) { breeze = x; }

private:
	int row;
	int col;
	int arrow;
	bool gold;

	bool glitter; //clues
	bool horrible_smell;
	bool breeze;
};

#endif ROBOTCLASS_H