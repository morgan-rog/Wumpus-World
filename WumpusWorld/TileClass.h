#pragma once
#ifndef TILECLASS_H
#define TILECLASS_H
#include <iostream>

class Tile {
public:
	Tile() { SetEmpty(); }
	void SetWumpus() { type = 'W'; } //sets tile as the wumpus
	void SetGold() { type = 'G'; } //sets tile as the gold
	void SetRuby() { type = 'R'; } //sets tile as the ruby
	void SetEmpty() { type = 'N'; }
	void SetPit() { type = 'P'; }
	void SetRobot() { type = '~'; }
	void SetLadder() { type = 'L'; }
	char GetType() { return type; }
	char GetHiddenType() { return hidden_type; }
	

private:
	char type;
	char hidden_type = ' ';
	
};

#endif