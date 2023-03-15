#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "LeetCodeGraphMiscs.hpp"
#include "LeetcodeLinkListMiscs.hpp"
#include "LeetcodeTreeMiscs.hpp"

enum class LTestTupleType : int
{
	None,
	IntType,
	DoubleType,
	StrType,
	Int1DArrType,
	Int2DArrType,
	Double1DArrType,
	Double2DArrType,
	Str1DArrType,
	Str2DArrType,
	LinkListType,
	TreeType,
	GraphType,
};

class LTestTuple
{
public:
	~LTestTuple()
	{
		this->Release();
	}
	
	// Copy Constructor
	LTestTuple(LTestTuple &tup)
	{}

	// Move Constructor
	LTestTuple(LTestTuple &&tup)
	{}

	// Here are all constructor
	LTestTuple(int val, std::string paramName = "")
	{
		this->mType = LTestTupleType::IntType;
		this->mIValue = val;
		this->mParameterName = paramName;
	}

	// Here are all getter
	LTestTupleType GetType()
	{
		return this->mType;
	}

	std::string& GetParameterName()
	{
		return this->mParameterName;
	}

	int GetIntValue()
	{
		if (this->mType != LTestTupleType::IntType)
			throw "This LTestTuple not IntType";

		return this->mIValue;
	}

	std::vector<int>& GetInt1DArray()
	{
		return this->mI1DArrValue;
	}

private:
	LTestTupleType mType = LTestTupleType::None;	
	std::string mParameterName = "";
	// values
	int mIValue = 0.0;
	double mDValue = 0.0;
	std::string mSValue = "";
	std::vector<int> mI1DArrValue;
	std::vector<std::vector<int>> mI2DArrValue;
	std::vector<double> mD1DArrValue;
	std::vector<std::vector<double>> mD2DArrValue;
	std::vector<std::string> mS1DArrValue;
	std::vector<std::vector<std::string>> mS2DArrValue;
	ListNode* mListHeadValue = nullptr;
	TreeNode* mTreeRootValue = nullptr;
	Node* mGraphValue = nullptr;

	void Release()
	{
		if (this->mTreeRootValue) {
			delete this->mTreeRootValue;
			this->mTreeRootValue = nullptr;
		}

		if (this->mGraphValue) {
			delete this->mGraphValue;
			this->mGraphValue = nullptr;
		}

		if (this->mListHeadValue) {
			delete this->mListHeadValue;
			this->mListHeadValue = nullptr;
		}

	}
};