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

private:
	int row;
	int col;
	int arrow;
	bool gold;
};

#endif ROBOTCLASS_H