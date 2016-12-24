#pragma once
#include "board.h"

class View {
public:
	View(Board& board);
	void showBoard(); //вывод доски на экран
	void doGameCycle();//основной цикл игры: ввод хода, вывод на экран доски, проверка текущего состояния
private:
	Board& board;
};
