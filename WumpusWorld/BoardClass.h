#pragma once
#ifndef BOARDCLASS_H
#define BOARDCLASS_H
#include "TileClass.h"
#include "RobotClass.h"

class Board {
public:
	Board() { create_board(); }
	void create_board(); //sets wumpus and gold
	void run_game1(); //game phase 1
	void run_game2(); //game phase 2
	void print_welcome_menu();
	void print_phase2_menu();
	void print_board();
	bool check_tile_pit_or_wumpus(); //if true-->game continues, if false-->gameover
	bool check_tile_gold();
	bool check_robot_gold() { return robot->GetGold(); } //checks if robot has collected the gold
	void reset_robot_tile() { board[robot->GetRow()][robot->GetCol()].SetType('N'); } //resets current robot tile
	bool check_tile_clues(); //if true, ask robot if shooting wumpus 
	bool shoot_wumpus();
	bool check_ladder();

private:
	Tile board[4][4];
	Robot* robot = new Robot();

};
#endif BOARDCLASS_H