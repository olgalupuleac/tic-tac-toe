#pragma once
#include <ncurses.h>
#include "board.h"

class CView {
public:
	CView(Board& board);
	~CView();
	void showBoard();
	void doGameCycle();//�������� ���� ����: ���� ����, ����� �� ����� �����, �������� �������� ���������
private:
	Board& board;
};
