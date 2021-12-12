#include "OperationTimes.hpp"

OperationTimes::OperationTimes()
{

}

OperationTimes::~OperationTimes()
{

}

int OperationTimes::Solution(std::string S)
{
	int times = 0;
	const char* s_ptr = S.c_str();

	int findFirstZeroIndex = 0;
	while(*(s_ptr + findFirstZeroIndex) == '0'){
		findFirstZeroIndex = findFirstZeroIndex + 1;
	}
	findFirstZeroIndex = findFirstZeroIndex < 0 ? findFirstZeroIndex + 1 : findFirstZeroIndex - 1;

	int amountOfOne = 0, amountOfZero = 0;
	int calculateIndex = 0;
	calculateIndex = S.size() - 1;
	while(calculateIndex != findFirstZeroIndex){
		if(*(s_ptr + calculateIndex) == '1'){
			times = times + 2;
		}
		else{
			times = times + 1;
		}

		calculateIndex = calculateIndex - 1;
	}

	return times - 1;

}


// OperationTimes_firstVer
OperationTimes_firstVer::OperationTimes_firstVer()
{

}

OperationTimes_firstVer::~OperationTimes_firstVer()
{

}

int OperationTimes_firstVer::Solution(std::string S)
{
	int times = 0;

	int findFirstZeroIndex = 0;
	while(S[findFirstZeroIndex] == '0'){
		findFirstZeroIndex = findFirstZeroIndex + 1;
	}
	findFirstZeroIndex = findFirstZeroIndex < 0 ? findFirstZeroIndex + 1 : findFirstZeroIndex - 1;

	int calculateIndex = 0;
	calculateIndex = S.size() - 1;
	while(calculateIndex != findFirstZeroIndex){
		if(S[calculateIndex] == '1'){
			S[calculateIndex] = '0';
		}
		else if(S[calculateIndex] == '0'){
			calculateIndex = calculateIndex - 1;
		}

		times = times + 1;
	}
	times = times - 1;

	return times;


}


// OperationTimes_wxVer
OperationTimes_wxVer::OperationTimes_wxVer()
{

}

OperationTimes_wxVer::~OperationTimes_wxVer()
{

}

int OperationTimes_wxVer::Solution(std::string S)
{
	int times = 0;
#if 1
	const char* ptrSt = S.c_str();
	const unsigned int strLen = S.length();
	const char* ptrEnd = ptrSt + strLen;
	
	const char* ptrEndStr = ptrEnd - 1;
	while(ptrEndStr >= ptrSt)
	{
		if(*ptrEndStr == '1')
		{
			times += 1;
		}
		ptrEndStr--;
	}
	//shifting times...
	times += (int)strLen - 1;
	if(*ptrSt == '0')
	{
		times--;
	}
	//std::cout << S << ": " << times << std::endl;
#else

	int findFirstZeroIndex = 0;
	while(S[findFirstZeroIndex] == '0'){
		findFirstZeroIndex = findFirstZeroIndex + 1;
	}
	findFirstZeroIndex = findFirstZeroIndex < 0 ? findFirstZeroIndex + 1 : findFirstZeroIndex - 1;

	int calculateIndex = 0;
	calculateIndex = S.size() - 1;
	while(calculateIndex != findFirstZeroIndex){
		if(S[calculateIndex] == '1'){
			S[calculateIndex] = '0';
		}
		else if(S[calculateIndex] == '0'){
			calculateIndex = calculateIndex - 1;
		}

		times = times + 1;
	}
	times = times - 1;
#endif

	return times;

}