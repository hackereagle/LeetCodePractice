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