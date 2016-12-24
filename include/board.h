#pragma once
#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

enum status {
	in_progress,
	X_wins,
	O_wins,
	draw
};

class  Board {
public:
	Board();
	void move(int x, int y, char sign); //сделать ход
	bool canMove(int x, int y); //корректен ли ход
	status isWin(); // текущее состояние: играем дальше; ничья; 0 выиграли; X выиграли
					//Можно добавлять методы при необходимости.
	char getCell(int x, int y);
private:
	char _board[10][10];
	int adjacent(int x, int y, int dx, int dy);
	status _gameStatus;
	int _emptyCells;
};

#endif // BOARD_H_INCLUDED
