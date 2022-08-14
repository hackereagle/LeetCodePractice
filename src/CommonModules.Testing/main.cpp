#include <iostream>
#include "TestLeetcodeTreeMiscsClass.hpp"
#include "TestVectorMiscsClass.hpp"

int main(int argc, char** argv)
{
	TestVectorMiscsClass testVectorMiscsClass;
	testVectorMiscsClass.TestPrintAcceptTypeVector();
	testVectorMiscsClass.TestPrintNotAcceptTypeVector();
	testVectorMiscsClass.TestCheckingTwoVectorSimilar();
	testVectorMiscsClass.TestCheckingTwoVectorNotSimilar();

	TestLeetcodeTreeMiscsClass testLeetcodeTreeMiscsClass;
	testLeetcodeTreeMiscsClass.TestCreateTreeWithArrayAndRelease();
	testLeetcodeTreeMiscsClass.TestCheckingTwoTreeEqual();
	testLeetcodeTreeMiscsClass.TestCheckingTwoTreeNotEqual();

	getchar();
	return EXIT_SUCCESS;
}