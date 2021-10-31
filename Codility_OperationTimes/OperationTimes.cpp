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

	return times - 1;
}

int OperationTimes::Solution_DoBinOperation(std::string S)
{
	int times = 0;
	const char* s_ptr = S.c_str();

	int findFirstZeroIndex = 0;
	while(*(s_ptr + findFirstZeroIndex) & 48){
		findFirstZeroIndex = findFirstZeroIndex + 1;
	}
	findFirstZeroIndex = findFirstZeroIndex < 0 ? findFirstZeroIndex + 1 : findFirstZeroIndex - 1;

	int amountOfOne = 0, amountOfZero = 0;
	int calculateIndex = 0;
	calculateIndex = S.size() - 1;
	while(calculateIndex != findFirstZeroIndex){
		if(*(s_ptr + calculateIndex) & 49){
			times = times + 2;
		}
		else if(*(s_ptr + calculateIndex) & 48){
			times = times + 1;
		}
	}

	return times - 1;
}