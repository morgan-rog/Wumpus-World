#pragma once
#ifndef BOARDCLASS_H
#define BOARDCLASS_H
#include "TileClass.h"
#include "RobotClass.h"

class Board {
public:
	Board() { create_board(); }
	void create_board(); //calls set functions
	void set_empty_spaces();
	void set_ladder();
	void set_pit_spaces();
	void set_wumpus_and_gold();

	void run_game1(); //game phase 1
	void run_game2(); //game phase 2

	void print_welcome_menu();
	void print_phase2_menu();
	void print_hidden_board();
	void print_unhidden_board();

	bool check_tile_pit_or_wumpus(); //if true-->game continues, if false-->gameover
	bool check_tile_gold();
	bool check_tile_ruby();

	bool check_robot_gold() { return robot->GetGold(); } //checks if robot has collected the gold
	bool check_robot_ruby() { return robot->GetRuby(); }
	bool check_robot_ladder() { return robot->GetLadder(); }
	bool check_gameover() { return robot->GetGameOver(); }

	void reset_robot_tile() { board[robot->GetRow()][robot->GetCol()].SetEmpty(); } //resets current robot tile
	bool check_tile_clues(); //if true, ask robot if shooting wumpus 

	bool shoot_wumpus();
	bool check_ladder();

	void reset_game();
	void save_game();
	void update_robot_points();

private:
	Tile board[4][4];  //every tile is empty space to start
	Robot* robot = new Robot();

};
#endif BOARDCLASS_H