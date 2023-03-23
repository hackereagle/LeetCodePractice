#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "LeetCodeGraphMiscs.hpp"
#include "LeetcodeLinkListMiscs.hpp"
#include "LeetcodeTreeMiscs.hpp"

class LTestTuple;
std::string GetParameterValueWithString(LTestTuple &tuple);

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
	/*#ifdef _UNIT_TEST_
		std::cout << "LTestTuple deconstructor be called! " << this->mParameterName << " be destroyed!" << std::endl;
	#endif*/
		this->Release();
	}
	
	// Copy Constructor
	LTestTuple(LTestTuple &tup)
	{
	#ifdef _UNIT_TEST_
		std::cout << "LTestTuple copy constructor be called!" << std::endl;
	#endif
		this->mParameterName = tup.GetParameterName();
		this->mType = tup.GetType();

		std::cout << "1" << std::endl; // debug
		this->mIValue = tup.GetIntValue();
		// TODO: All vector were return vector reference. So need to copy vector instead of assign.
		this->mI1DArrValue = tup.GetInt1DArray();
		this->mI2DArrValue = tup.GetInt2DArray();

		std::cout << "2" << std::endl; // debug
		this->mDValue = tup.GetDoubleValue();
		this->mD1DArrValue = tup.GetDouble1DArray();
		this->mD2DArrValue = tup.GetDouble2DArray();

		std::cout << "3" << std::endl; // debug
		this->mSValue = tup.GetStrValue();
		this->mS1DArrValue = tup.GetStr1DArray();
		this->mS2DArrValue = tup.GetStr2DArray();

		std::cout << "4" << std::endl;
		this->mListHeadValue = CopyListNode(tup.GetListHead());
		this->mGraphValue = CopyGraph(tup.GetGraph());
		this->mTreeRootValue = CopyTree(tup.GetTreeRoot());
	}

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

	LTestTuple(std::vector<int> val, std::string paramName = "")
	{
		this->mType = LTestTupleType::Int1DArrType;
		this->mI1DArrValue = val;
		this->mParameterName = paramName;
	}

	LTestTuple(ListNode* head, std::string paramName = "")
	{
		this->mType = LTestTupleType::LinkListType;
		this->mListHeadValue = head;
		this->mParameterName = paramName;
	}

	// Here are all getter
	LTestTupleType GetType() const
	{
		return this->mType;
	}

	const std::string& GetParameterName()
	{
		return this->mParameterName;
	}

	// related int
	int GetIntValue()
	{
		if (this->mType != LTestTupleType::IntType)
			throw "This LTestTuple not IntType";

		return this->mIValue;
	}

	std::vector<int>& GetInt1DArray()
	{
		if (this->mType != LTestTupleType::Int1DArrType)
			throw "This LTestTuple not Int1DArrType";

		return this->mI1DArrValue;
	}

	std::vector<std::vector<int>> &GetInt2DArray()
	{
		if (this->mType != LTestTupleType::Int2DArrType)
			throw "This LTestTuple not Int2DArrType";

		return this->mI2DArrValue;
	}

	// related double
	double GetDoubleValue()
	{
		if (this->mType != LTestTupleType::DoubleType)
			throw "This LTestTuple not DoubleType";

		return this->mDValue;
	}

	std::vector<double>& GetDouble1DArray()
	{
		if (this->mType != LTestTupleType::Double1DArrType)
			throw "This LTestTuple not Double1DArrType";

		return this->mD1DArrValue;
	}

	std::vector<std::vector<double>> &GetDouble2DArray()
	{
		if (this->mType != LTestTupleType::Double2DArrType)
			throw "This LTestTuple not Double2DArrType";

		return this->mD2DArrValue;
	}

	// related string
	std::string GetStrValue()
	{
		if (this->mType != LTestTupleType::StrType)
			throw "This LTestTuple not StrType";

		return this->mSValue;
	}

	std::vector<std::string>& GetStr1DArray()
	{
		if (this->mType != LTestTupleType::Str1DArrType)
			throw "This LTestTuple not Str1DArrType";

		return this->mS1DArrValue;
	}

	std::vector<std::vector<std::string>> &GetStr2DArray()
	{
		if (this->mType != LTestTupleType::Str2DArrType)
			throw "This LTestTuple not Str2DArrType";

		return this->mS2DArrValue;
	}

	// related pointer type
	ListNode* GetListHead()
	{
		if (this->mType != LTestTupleType::LinkListType)
			throw "This LTestTuple not LinkListType";

		return this->mListHeadValue;
	}

	Node* GetGraph()
	{
		if (this->mType != LTestTupleType::GraphType)
			throw "This LTestTuple not GraphType";

		return this->mGraphValue;
	}

	TreeNode* GetTreeRoot()
	{
		if (this->mType != LTestTupleType::TreeType)
			throw "This LTestTuple not TreeType";

		return this->mTreeRootValue;
	}

	friend std::ostream &operator<<(std::ostream &os, LTestTuple &tup)
	{
		return os << tup.GetParameterName() << ": " << GetParameterValueWithString(tup);
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
		ReleaseTree(this->mTreeRootValue);
		ReleaseAdjList(this->mGraphValue);
		ReleaseList(this->mListHeadValue);

	}

};

inline std::string GetParameterValueWithString(LTestTuple &tuple)
{
	std::string ret = "";

	if (LTestTupleType::IntType == tuple.GetType()) {
		ret = std::to_string(tuple.GetIntValue());
	}
	else if (LTestTupleType::Int1DArrType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::Int2DArrType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::DoubleType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::Double1DArrType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::Double2DArrType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::StrType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::Str1DArrType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::Str2DArrType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::GraphType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::LinkListType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::TreeType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else if (LTestTupleType::Int1DArrType == tuple.GetType()) {
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	else{
		throw "GetParameterValueWithString not implement this type of LTestTuple";
	}
	return ret;
}