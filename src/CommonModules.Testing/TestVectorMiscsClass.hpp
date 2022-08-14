#pragma once

#include <iostream>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class TestVectorMiscsClass
{
public:
	TestVectorMiscsClass()
	{}

	~TestVectorMiscsClass()
	{}

	void TestPrintAcceptTypeVector()
	{
		std::cout << "========== Test Print Accept Type Vector ==========" << std::endl;
		std::cout << "" << std::endl;
		std::vector<int> test(3, 500);
		PrintVector<int>(test);
	}

	void TestPrintNotAcceptTypeVector()
	{
		std::cout << "========== Test Print Not Accept Type Vector ==========" << std::endl;
		std::vector<struct otherStruct> test;
		test.push_back(OtherStruct(1));
		test.push_back(OtherStruct(1));
		PrintVector<struct otherStruct>(test);
	}

	void TestCheckingTwoVectorSimilar()
	{
		std::cout << "========== Test Checking Two Vector Similar ==========" << std::endl;
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		PrintVector<int>(v1);

		std::vector<int> v2;
		v2.push_back(2);
		v2.push_back(1);
		v2.push_back(3);
		PrintVector<int>(v2);

		bool isSimilar = IsTwoVectorSimilar<int>(v1, v2);
		AssertClass::GetInstance().Assert(isSimilar == true);
	}

	void TestCheckingTwoVectorNotSimilar()
	{
		std::cout << "========== Test Checking Two Vector Not Similar ==========" << std::endl;
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		PrintVector<int>(v1);

		std::vector<int> v2;
		v2.push_back(2);
		v2.push_back(1);
		v2.push_back(5);
		PrintVector<int>(v2);

		bool isSimilar = IsTwoVectorSimilar<int>(v1, v2);
		AssertClass::GetInstance().Assert(isSimilar == false);
	}

private:
	typedef struct otherStruct{
		otherStruct(int val)
		{
			member = val;
		}
		int member = 0;

		friend std::ostream& operator<<(std::ostream& stream, const otherStruct& s)
		{
			stream << s.member;
			return stream;
		}

	}OtherStruct;
};