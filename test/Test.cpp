#include <iostream>
#include "../include/Test.h"

int Test::failedNum = 0;
int Test::totalNum = 0;

void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
	totalNum++;
	if (!expr) {
		failedNum++;
		std::cout << "test failed: " << func << " in " << filename << ":" << lineNum << std::endl;
	}
}

void Test::showFinalResult() {
	if (!failedNum) std::cout << "All tests passed.\n";
	else std::cout << "Failed " << failedNum << " of " << totalNum << " tests.\n";
}
