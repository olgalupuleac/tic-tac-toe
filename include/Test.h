#pragma once
#define DO_CHECK(EXPR) check(EXPR, __func__, __FILE__, __LINE__)

class Test {
protected:
	static int failedNum; // ���������� ������, ������� ���������
	static int totalNum;  // ����� ���������� ������
public:
	/*
	���� ������� expr �� ���������, �� ������� check ������� ���������� �� ������; ��� ���������� ������ ��������� ��� ������� � ������, ��� ����� � ������ � ����� ������, �� ������� ���������� ����� check (��������, �test failed: testIsWIn() in TestBoard.cpp:34�).
	*/
	static void check(bool expr, const char *func, const char  *filename, size_t lineNum);


	/*
	������� ������� ��������� ���������� ������������, ��������, �All test passed.� ��� �Failed 2 of 8 tests.�.
	*/
	static void showFinalResult();


	/*
	��� ������� ��������� ��� ����� �� ������������ ������. ������ ��� ������� ����������� �� main � test.cpp.
	*/
	virtual void runAllTests() = 0;
};

