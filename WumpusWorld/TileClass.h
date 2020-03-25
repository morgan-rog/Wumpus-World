#pragma once
#ifndef TILECLASS_H
#define TILECLASS_H
#include <iostream>
#include <vector>

class Tile { //tile class initialy decides if tile is a pit or not, then board class sets wumpus and gold
public:
	Tile() { SetTilePits(); }
	void SetTilePits();
	void SetWumpus() {type = 'W';}
	void SetGold() { type = 'G'; }
	char GetType() { return type; }
	char GetHiddenType() { return hidden_type; }
	void SetType(char c) { type = c; }
private:
	char type;
	char hidden_type = ' ';
};

#endif