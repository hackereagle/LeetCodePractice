#pragma once
// In oder to test difference method, defined a interface

class IOperationTimes
{
public:
	~IOperationTimes(){}
	virtual int Solution(std::string S) = 0;
};