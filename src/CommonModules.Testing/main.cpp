#include <iostream>
#include "TestLeetcodeTreeMiscsClass.hpp"
#include "TestVectorMiscsClass.hpp"
#include "TestLeetcodeGraphMiscsClass.hpp"
#include "TestStopWatch.hpp"

int main(int argc, char** argv)
{
	// TestVectorMiscsClass testVectorMiscsClass;
	// testVectorMiscsClass.TestPrintAcceptTypeVector();
	// testVectorMiscsClass.TestPrintNotAcceptTypeVector();
	// testVectorMiscsClass.TestCheckingTwoVectorSimilar();
	// testVectorMiscsClass.TestCheckingTwoVectorNotSimilar();

	// TestLeetcodeTreeMiscsClass testLeetcodeTreeMiscsClass;
	// testLeetcodeTreeMiscsClass.TestCreateTreeWithArrayAndRelease();
	// testLeetcodeTreeMiscsClass.TestCheckingTwoTreeEqual();
	// testLeetcodeTreeMiscsClass.TestCheckingTwoTreeNotEqual();

	// TestLeetcodeGraphMiscClass testLeetcodeGraphMiscClass;
	// testLeetcodeGraphMiscClass.TestGenerateAdjList();

	TestStopWatch testStopWatch;
	testStopWatch.TestCallStopWatchOnce();
	testStopWatch.TestCallStopWatchMultiple();

	getchar();
	return EXIT_SUCCESS;
}