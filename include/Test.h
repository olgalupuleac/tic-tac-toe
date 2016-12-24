#pragma once
#define DO_CHECK(EXPR) check(EXPR, __func__, __FILE__, __LINE__)

class Test {
protected:
	static int failedNum; // количество тестов, которые сломались
	static int totalNum;  // общее количество тестов
public:
	/*
	≈сли условие expr не выполнено, то функци€ check выводит информацию об ошибке; эта информаци€ должна содержать им€ функции с тестом, им€ файла с тестом и номер строки, на которой находитьс€ вызов check (например, Уtest failed: testIsWIn() in TestBoard.cpp:34Ф).
	*/
	static void check(bool expr, const char *func, const char  *filename, size_t lineNum);


	/*
	‘ункци€ выводит финальную статистику тестировани€, например, УAll test passed.Ф или УFailed 2 of 8 tests.Ф.
	*/
	static void showFinalResult();


	/*
	Ёта функци€ запускает все тесты из производного класса. »менно эта функци€ запускаетс€ из main в test.cpp.
	*/
	virtual void runAllTests() = 0;
};

