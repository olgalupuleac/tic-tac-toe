#include "view.h"

int main() {
	Board board;
	View viewboard = View(board);
	viewboard.doGameCycle();
	return 0;
}