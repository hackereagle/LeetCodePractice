#include <unordered_map>
#include <vector>
#include "FindSmallestUniqueSubstring.hpp"

FindSmallestUniqueSubstring::FindSmallestUniqueSubstring()
{}

FindSmallestUniqueSubstring::~FindSmallestUniqueSubstring()
{}

int FindSmallestUniqueSubstring::Solution(std::string S, std::string& result)
{
	int len = -1;

	size_t strLen = S.size();
	size_t start = 0, end = 0;
	std::unordered_map<std::string, int> countTable;
	int substrLen;
	std::string substr;
	while(start < strLen){
		substrLen = end - start + 1;
		substr =  S.substr(start, substrLen);
		countTable[substr]++;

		end = end + 1;
		if(end > strLen){
			start = start + 1;
			end = start;
		}
	}

	len = strLen;
	result = S;
	int _len = 0;
	for(auto& it : countTable){
		_len = it.first.size();
		if(_len < len && it.second == 1){
			result = it.first;
			len = _len;
		}
	}

	return len;
}


// Optimized by erasing not unique substring as iterate string.
FindSmallestUniqueSubstring_OptimalByEraseNotUnique::FindSmallestUniqueSubstring_OptimalByEraseNotUnique()
{}

FindSmallestUniqueSubstring_OptimalByEraseNotUnique::~FindSmallestUniqueSubstring_OptimalByEraseNotUnique()
{}

int FindSmallestUniqueSubstring_OptimalByEraseNotUnique::Solution(std::string S, std::string& result)
{
	int len = -1;

	size_t strLen = S.size();
	size_t start = 0, end = 0;
	std::unordered_map<std::string, int> countTable;
	std::unordered_map<std::string, int> uniqueSubstr;
	int substrLen;
	std::string substr;
	while(start < strLen){
		substrLen = end - start + 1;
		substr =  S.substr(start, substrLen);
		auto element = countTable.find(substr);
		if(element != countTable.end()){
			countTable[substr] = 1;
			uniqueSubstr[substr] = 1;
		}
		else{
			countTable[substr]++;
			uniqueSubstr.erase(substr);
		}

		end = end + 1;
		if(end > strLen){
			start = start + 1;
			end = start;
		}
	}

	len = strLen;
	result = S;
	int _len = 0;
	for(auto& it : uniqueSubstr){
		_len = it.first.size();
		if(_len < len){
			result = it.first;
			len = _len;
		}
	}

	return len;
}