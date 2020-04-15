#pragma once
#ifndef ROBOTCLASS_H
#define ROBOTCLASS_H
#include <iostream>
using namespace std;

class Robot {
public:
	Robot() { ResetRobot(); }
	void SetRow(int r) { row = r; }
	void SetCol(int c) { col = c; }

	int GetRow() { return row; }
	int GetCol() { return col; }

	int GetArrow() { return arrow; }
	void LoseArrow() { arrow -= 1; }

	int GetPoints() { return total_points; }
	void SetTotalPoints(int x) { total_points = x; }
	void AddGoldPoints() { total_points += 50; }
	void AddRubyPoints() { total_points += 100; }
	void LoseWumpusPoints();
	void LosePitPoints();
		

	void ChooseMove();
	void SetGoldTrue() { gold = true; }
	void SetRubyTrue() { ruby = true; }
	void SetLadderTrue() { ladder = true; }

	bool GetGold() { return gold; }
	bool GetRuby() { return ruby; }
	bool GetLadder() { return ladder; }
	bool GetGlitter() { return glitter; }
	bool GetSmell() { return horrible_smell; }
	bool GetBreeze() { return breeze; }
	bool GetRedGlitter() { return red_glitter; }

	void SetGlitter(bool x) { glitter = x; }
	void SetSmell(bool x) { horrible_smell = x; }
	void SetBreeze(bool x) { breeze = x; }
	void SetRedGlitter(bool x) { red_glitter = x; }

	bool GetGameOver() { return gameover; }
	void SetGameOver(bool x) { gameover = x; }

	void ResetRobot();

private:
	int row = 0;
	int col = 0;
	int arrow;
	int total_points = 0;

	bool gold;
	bool ruby;
	bool ladder;

	bool glitter; //clues
	bool red_glitter;
	bool horrible_smell;
	bool breeze;

	bool gameover;

};

#endif ROBOTCLASS_H