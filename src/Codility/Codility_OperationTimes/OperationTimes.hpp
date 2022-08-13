#ifndef _OPERATION_H_
#define _OPERATION_H_

#include <string>
#include "IOperationTimes.hpp"

class OperationTimes : public IOperationTimes
{
public:
	OperationTimes();
	~OperationTimes();
	int Solution(std::string S);

private:
};

class OperationTimes_firstVer : public IOperationTimes
{
public:
	OperationTimes_firstVer();
	~OperationTimes_firstVer();
	int Solution(std::string S);

private:
};

class OperationTimes_wxVer : public IOperationTimes
{
public:
	OperationTimes_wxVer();
	~OperationTimes_wxVer();
	int Solution(std::string S);

private:
};
#endif //_OPERATION_H_