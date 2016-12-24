#include "BoardTest.h"

void BoardTest::testGetCell1() {
	Board b;
	DO_CHECK(b.getCell(0, 0) == '.');
}

void BoardTest::testGetCell2() {
	Board b;
	b.move(0, 0, 'X');
	DO_CHECK(b.getCell(0, 0) == 'X');
}

void BoardTest::testGetCell3() {
	Board b;
	b.move(0, 0, 'O');
	DO_CHECK(b.getCell(0, 0) == 'O');
}

void BoardTest::testIsWinInProgress() {
	Board b;
	b.move(0, 0, 'O');
	b.move(0, 1, 'O');
	b.move(1, 0, 'O');
	b.move(4, 5, 'X');
	b.move(5, 5, 'X');
	DO_CHECK(b.isWin() == in_progress);
}

void BoardTest::testIsWinXWins() {
	Board b;
	b.move(0, 0, 'X');
	b.move(0, 1, 'X');
	b.move(0, 2, 'X');
	b.move(0, 3, 'X');
	b.move(0, 4, 'X');
	DO_CHECK(b.isWin() != X_wins);
}

void BoardTest::testIsWinOWins() {
	Board b;
	b.move(0, 0, 'O');
	b.move(0, 1, 'O');
	b.move(0, 2, 'O');
	b.move(0, 3, 'O');
	b.move(0, 4, 'O');
	DO_CHECK(b.isWin() == O_wins);
}

void BoardTest::testIsWinDraw() {
	Board b;
	char s[] = "XO";
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			b.move(i, j, s[(i + j / 2) % 2]);
	DO_CHECK(b.isWin() == draw);
}

void BoardTest::testMove1() { //puts X
	Board b;
	b.move(0, 0, 'X');
	DO_CHECK(b.getCell(0, 0) == 'X');
}

void BoardTest::testMove2() { //puts O
	Board b;
	b.move(0, 0, 'O');
	DO_CHECK(b.getCell(0, 0) == 'O');
}

void BoardTest::testMove3() { //checks that other cells wasn't changed
	Board b;
	b.move(0, 0, 'X');
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
	        if (i || j) DO_CHECK(b.getCell(i, j) == '.'); //number of tests here is 100 because we call DO_CHECK 100 timess
}

void BoardTest::testCanMove1() {
	Board b;
	b.move(0, 0, 'X');
	DO_CHECK(!b.canMove(0, 0));
}

void BoardTest::testCanMove2() {
	Board b;
	b.move(0, 0, 'O');
	DO_CHECK(b.canMove(1, 1));
}

void BoardTest::testCanMove3() {
	Board b;
	DO_CHECK(!b.canMove(10, 1));
}

void BoardTest::runAllTests() {
	testCanMove1();
	testCanMove2();
	testCanMove3();
	testGetCell1();
	testGetCell2();
	testGetCell3();
	testMove1();
	testMove2();
	testMove3();
	testIsWinDraw();
	testIsWinInProgress();
	testIsWinOWins();
	testIsWinXWins();
}
