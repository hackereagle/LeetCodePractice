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