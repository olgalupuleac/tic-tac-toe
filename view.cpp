#include <iostream>
#include "view.h"
//#define DEBUG

char players[2] = { 'O', 'X' };

View::View(Board& board): board(board) {
}

void View::showBoard() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			std::cout << board.getCell(i, j);
		std::cout << '\n';
	}
		
}

void View::doGameCycle() {
	int cur = 0;
	while (board.isWin() == in_progress) {
		showBoard();
		std::cout << players[cur] << " move: ";
		int x, y;
		std::cin >> x >> y;
		//std::cout << '\n';
		while (!(x == -1 && y == -1) && !board.canMove(x, y)) {
			std::cout << "Bad move!\n";
#ifdef DEBUG
			std::cout << board.getCell(x, y) << '\n';
#endif // DEBUG
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