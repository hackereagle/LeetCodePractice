#include <iostream>
#include <gtest/gtest.h>
#include "TestLeetcodeTreeMiscsClass.hpp"
#include "TestVectorMiscsClass.hpp"
#include "TestLeetcodeGraphMiscsClass.hpp"
#include "TestStopWatch.hpp"
#include "TestLeetcodeLinkListMiscsClass.hpp"

int main(int argc, char** argv)
{
	// TestVectorMiscsClass testVectorMiscsClass;
	// testVectorMiscsClass.TestPrintAcceptTypeVector();
	// testVectorMiscsClass.TestPrintNotAcceptTypeVector();
	// testVectorMiscsClass.TestCheckingTwoVectorSimilar();
	// testVectorMiscsClass.TestCheckingTwoVectorNotSimilar();

	// TestLeetcodeGraphMiscClass testLeetcodeGraphMiscClass;
	// testLeetcodeGraphMiscClass.TestGenerateAdjList();

	// TestStopWatch testStopWatch;
	// testStopWatch.TestCallStopWatchOnce();
	// testStopWatch.TestCallStopWatchMultiple();

	// getchar();
	//return EXIT_SUCCESS;

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}