#include "FindMinAmplitude.hpp"
#include <iostream>

FindMinAmplitude::FindMinAmplitude()
{}

FindMinAmplitude::~FindMinAmplitude()
{}

int FindMinAmplitude::Solution(std::vector<int> A, int K)
{
	// initialize result.
	int min_amp = 1 << 30;

	size_t len = A.size();
	if(K > len){
		std::cout << "K bigger than input array size" << std::endl;
		throw new std::exception();
	}

	int temp_amp = 0, index = 0;
	for(int i = 0; i <= len - K; i++){
		std::vector<int> removedResult = this->CalculateRemoveConsecutiveElementsArrayFromIndex(A, i, K);
		//this->PrintVector(removedResult);
		temp_amp = this->CalculateAmplitude(removedResult);	

		if(temp_amp < min_amp){
			min_amp = temp_amp;
			index = i;
		}
	}

	this->PrintVector(this->CalculateRemoveConsecutiveElementsArrayFromIndex(A, index, K));
	return min_amp;
}

std::vector<int> FindMinAmplitude::CalculateRemoveConsecutiveElementsArrayFromIndex(std::vector<int> array, int index, int amountOfRemoved)
{
	std::vector<int> result = array;
	int end = index + amountOfRemoved;
	result.erase(result.begin() + index, result.begin() + end);
	return result;
}

void FindMinAmplitude::PrintVector(std::vector<int> vec)
{
	size_t len = vec.size();
	std::cout << "[";
	for(int i = 0; i < len; i++){
		std::cout << vec[i];

		if(i != len - 1)
			std::cout << ",";
	}
	std::cout << "]" << std::endl;
}

int FindMinAmplitude::CalculateAmplitude(std::vector<int> array)
{
	int _max = array[0], _min = array[0];
	size_t len = array.size();
	for(int i = 1; i < len; i++){
		if(array[i] > _max)
			_max = array[i];
		
		if(array[i] < _min)
			_min = array[i];
	}
	return _max - _min;
}