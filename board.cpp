#include <cstdlib>
#include <iostream>
#include <utility>
#include "board.h"

std::pair<int, int> shifts[] = { std::make_pair(1, 0) ,
                                 std::make_pair(0, 1) , 
	                             std::make_pair(1, 1) , 
	                             std::make_pair(1, -1) };

bool on_board(int x, int y) {
	return (x < 10 && y < 10 && x >= 0 && y >= 0);
}

Board::Board() {
	_gameStatus = in_progress;
	_emptyCells = 100;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			_board[i][j] = '.';
}

void Board::move(int x, int y, char sign) {
	_board[x][y] = sign;
	_emptyCells--;
	for (auto shift : shifts)
		if (adjacent(x, y, shift.first, shift.second) + adjacent(x, y, -shift.first, -shift.second) >= 6) {
#ifdef DEBUG
			std::cout << x <<'  ' << y << ' ' << shift.first << ' ' << shift.second << ' ' << adjacent(x, y, shift.first, shift.second) << ' ' << adjacent(x, y, -shift.first, -shift.second)\n';
#endif // DEBUG
			if (sign == 'X') _gameStatus = X_wins;
			else _gameStatus = O_wins;
			return;
		}
	if (!_emptyCells) _gameStatus = draw;
}

status Board::isWin() {
	return _gameStatus;
}

bool Board::canMove(int x, int y) {
	return on_board(x, y) && _board[x][y] == '.';
}

char Board::getCell(int x, int y) {
	return _board[x][y];
}

int Board::adjacent(int x, int y, int dx, int dy) {
	int x_cur = x;
	int y_cur = y;
	int cnt = 0;
	while (on_board(x_cur, y_cur) && cnt < 5 && _board[x][y] == _board[x_cur][y_cur]) {
		cnt++;
		x += dx;
		y += dy;
	}
	return cnt;
}
