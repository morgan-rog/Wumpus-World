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
	void ChooseMove();

private:
	int row;
	int col;
	int arrow;
};

#endif ROBOTCLASS_H