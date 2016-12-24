#include <iostream>
#include <conio.h>
#include "../include/cursesview.h"
//#define DEBUG

char players[2] = { 'O', 'X' };

void move_cursor(char c){

}

CView::CView(Board& board): board(board) {
	initscr();
	keypad(stdsrc, 1);
}

CView::~CView(){
	endwin();
}

void CView::showBoard() {
	refresh();
}

void CView::doGameCycle() {
	int cur = 0;
	while (board.isWin() == in_progress) {
		int x = 0;
		int y = 0;
		//move(0, 0);
		showBoard();
		char c = getch();

		std::cout << players[cur] << " move: ";
		while (!(x == -1 && y == -1) && !board.canMove(x, y)) {
			std::cout << "Bad move!\n";
			std::cout << players[cur] << " move: ";
			std::cin >> x >> y;
		}
		if (x == -1 && y == -1) break;
		board.move(x, y, players[cur]);
		std::cout << '\n';
		cur = 1 - cur;
	}
	if (board.isWin() == X_wins) std::cout << "X wins!\n";
	else if (board.isWin() == O_wins) std::cout << "O wins!\n";
	else std::cout << "Draw.\n";
}