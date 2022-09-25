#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "StringMiscs.hpp"

template<class T>
inline bool IsAcceptType()
{
	bool isAcceptType = false;
	if(std::is_same<T, int>::value ||
	   std::is_same<T, float>::value ||
	   std::is_same<T, double>::value ||
	   std::is_same<T, std::string>::value){
		isAcceptType = true;
	}
	else{
		isAcceptType = false;
	}

	return isAcceptType;
}

template<class T>
inline void PrintVector(std::vector<T> vec)
{
	if(IsAcceptType<T>()){
		std::cout << "[";
		int len = vec.size();
		if(len > 0){
			std::cout << vec[0];
			for(int i = 1; i < len; i++){
				std::cout << ", " << vec[i];
			}
		}
		std::cout << "]" <<std::endl;
	}
	else{
		std::cout << "PrintVector could not print this type" << std::endl;
	}
}

template<>
inline void PrintVector<std::vector<int>>(std::vector<std::vector<int>> vec)
{
	int len = vec.size();
	std::cout << "[";
	for(int i = 0; i < len; i++){
		if(i > 0)
			std::cout << ", ";

		std::cout << "[";
		int _len = vec[i].size();
		if(_len > 0){
			std::cout << vec[i][0];
			for(int j = 1; j < _len; j++){
				std::cout << ", " << vec[i][j];
			}
		}
		std::cout << "]";
	}
	std::cout << "]" <<std::endl;
}

template<class T>
inline bool IsTwoVectorEqual(std::vector<T> vec1, std::vector<T>vec2)
{
	bool isEqual = false;
	if(IsAcceptType<T>()){
		size_t len1 = vec1.size(), len2 = vec2.size();
		if(len1 == 0 && len2 == 0){
			isEqual = true;
		}
		else if(len1 == len2){
			typename std::vector<T>::iterator it1 = vec1.begin(), e1 = vec1.end();
			for(typename std::vector<T>::iterator it2 = vec2.begin(); it1 != e1; it1++, it2++){
				if(*it1 != *it2){
					isEqual = false;
					break;
				}
				else{
					isEqual = true;
				}
			}
		}
		else{
			isEqual = false;
		}
	}
	else{
		std::cout << "IsTwoVectorEqual could not print this type" << std::endl;
		isEqual = false;
	}
	return isEqual;
}

template<class T>
inline bool IsTwoVectorSimilar(std::vector<T> vec1, std::vector<T>vec2)
{
	bool isSimilar = false;
	if(IsAcceptType<T>()){
		size_t len1 = vec1.size(), len2 = vec2.size();
		if(len1 == len2){
			std::unordered_map<T, int> count;
			for(typename std::vector<T>::iterator it1 = vec1.begin(), e1 = vec1.end(); it1 != e1; it1++){
				if(count.find(*it1) == count.end()){
					count[*it1] = 1;
				}
				else{
					count[*it1] = count[*it1] + 1;
				}
			}

			for(typename std::vector<T>::iterator it2 = vec2.begin(), e2 = vec2.end(); it2 != e2; it2++){
				if(count.find(*it2) == count.end()){
					count[*it2] = 1;
					break;
				}
				else{
					count[*it2] = count[*it2] + 1;
				}
			}

			for(typename std::unordered_map<T, int>::iterator p = count.begin(), e = count.end(); p != e; p++){
				if(p->second & 0x1){
					isSimilar = false;
					break;
				}
				else{
					isSimilar = true;
				}
			}
		}
		else{
			isSimilar = false;
		}
	}
	else{
		isSimilar = false;
	}
	return isSimilar;
}

// template<>
// inline bool IsTwoVectorSimilar<std::vector<int>>(std::vector<std::vector<int>> vec1, std::vector<std::vector<int>>vec2)
// {
// 	bool isSimilar = false;
// 	size_t len1 = vec1.size(), len2 = vec2.size();
// 	if(len1 == len2){
// 		// TODO: Implement std::vector<std::vector<int>> IsTowVectorSimilar, please refer to https://jimmy-shen.medium.com/stl-map-unordered-map-with-a-vector-for-the-key-f30e5f670bae
// 		std::unordered_map<std::vector<int>, int> count;
// 		for(std::vector<std::vector<int>>::iterator it1 = vec1.begin(), e1 = vec1.end(); it1 != e1; it1++){
// 			if(count.find(*it1) == count.end()){
// 				count[*it1] = 1;
// 			}
// 			else{
// 				count[*it1] = count[*it1] + 1;
// 			}
// 		}

// 		for(typename std::vector<std::vector<int>>::iterator it2 = vec2.begin(), e2 = vec2.end(); it2 != e2; it2++){
// 			if(count.find(*it2) == count.end()){
// 				count[*it2] = 1;
// 				break;
// 			}
// 			else{
// 				count[*it2] = count[*it2] + 1;
// 			}
// 		}

// 		for(typename std::unordered_map<std::vector<int>, int>::iterator p = count.begin(), e = count.end(); p != e; p++){
// 			if(p->second & 0x1){
// 				isSimilar = false;
// 				break;
// 			}
// 			else{
// 				isSimilar = true;
// 			}
// 		}
// 	}
// 	else{
// 		isSimilar = false;
// 	}
// 	return isSimilar;
// }

template<class T>
inline std::vector<T> ConvertArrayToVector(T arr[], int count)
{
	std::vector<T> ret;
	ret.resize(count);
	typename std::vector<T>::iterator it = ret.begin();
	for(int i = 0; i < count; i++){
		*(it + i) = arr[i];
	}

	return ret;
}

inline std::vector<int> ConvertStringToVector(std::string input)
{
	std::vector<int> ret;
	bool isFormat = false;
	isFormat = input[0] == '[';
	isFormat = isFormat & (input[input.size() - 1] == ']');
	if(isFormat){
		std::string nums = input.substr(1, input.size() - 2);
		std::vector<std::string> temp = SplitStringViaComma(nums);
		//PrintVector(temp);
		for(auto s : temp){
			ret.push_back(std::stoi(s));
		}
	}
	else{
		std::cout << "input was not vector format!" << std::endl;
	}

	return ret;
}