#pragma once

#include <vector>

class FindMinAmplitude
{
public:
	FindMinAmplitude();
	~FindMinAmplitude();
	int Solution(std::vector<int> A, int K);

private:
	std::vector<int> CalculateRemoveConsecutiveElementsArrayFromIndex(std::vector<int> array, int index, int amountOfRemoved);
	int CalculateAmplitude(std::vector<int> array);
	void PrintVector(std::vector<int> vec);
};