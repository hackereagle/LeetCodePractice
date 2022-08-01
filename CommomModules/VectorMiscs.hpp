#pragma once
#include <iostream>
#include <string>
#include <vector>

template<class T>
inline void PrintVector(std::vector<T> vec)
{
	if(std::is_same<T, int>::value ||
	   std::is_same<T, float>::value ||
	   std::is_same<T, double>::value ||
	   std::is_same<T, std::string>::value){

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

template<class T>
inline bool IsTwoVectorEqual(std::vector<T> vec1, std::vector<T>vec2)
{
	bool isEqual = false;
	if(std::is_same<T, int>::value ||
	   std::is_same<T, float>::value ||
	   std::is_same<T, double>::value ||
	   std::is_same<T, std::string>::value){
		size_t len1 = vec1.size(), len2 = vec2.size();
		if(len1 == len2){
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