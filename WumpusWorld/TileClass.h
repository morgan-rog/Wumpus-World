#pragma once
#ifndef TILECLASS_H
#define TILECLASS_H
#include <iostream>
#include <vector>

class Tile { //tile class initialy decides if tile is a pit or not, then board class sets wumpus and gold
public:
	Tile() { SetTilePits(); }
	void SetTilePits(); //sets all the tiles randomly to either empty or to a pit
	void SetWumpus() {type = 'W';} //sets tile as the wumpus
	void SetGold() { type = 'G'; } //sets tile as the gold
	char GetType() { return type; }
	char GetHiddenType() { return hidden_type; }
	void SetType(char c) { type = c; }
private:
	char type;
	char hidden_type = ' ';
};

#endif