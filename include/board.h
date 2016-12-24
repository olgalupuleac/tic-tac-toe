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
	void move(int x, int y, char sign); //������� ���
	bool canMove(int x, int y); //��������� �� ���
	status isWin(); // ������� ���������: ������ ������; �����; 0 ��������; X ��������
					//����� ��������� ������ ��� �������������.
	char getCell(int x, int y);
private:
	char _board[10][10];
	int adjacent(int x, int y, int dx, int dy);
	status _gameStatus;
	int _emptyCells;
};

#endif // BOARD_H_INCLUDED
