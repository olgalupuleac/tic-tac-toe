#pragma once
#include <cstddef>
#include "Test.h"
#include "board.h"

class BoardTest : public Test {
public:
	void testGetCell1();
	void testGetCell2();
	void testGetCell3();
	void testIsWinInProgress();
	void testIsWinXWins();
	void testIsWinOWins();
	void testIsWinDraw();
	void testMove1();
	void testMove2();
	void testMove3();
	void testCanMove1();
	void testCanMove2();
	void testCanMove3();
	void runAllTests();
};
