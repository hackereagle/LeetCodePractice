#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

inline std::vector<std::string> SplitString(std::string str, std::string delimiter)
{
    std::vector<std::string> ret;

    size_t strLen = str.size();
    if(strLen > 0){
        size_t pos = 0;
        while ((pos = str.find(delimiter)) != std::string::npos) {
            ret.push_back(str.substr(0, pos));
            str.erase(0, pos + delimiter.length());
        }
        ret.push_back(str);
    }

    return ret; 
}

inline std::vector<std::string> SplitStringViaComma(std::string str)
{
	return SplitString(str, ",");
}

inline std::vector<std::string> SplitStringViaSemicolon(std::string str)
{
	return SplitString(str, ";");
}

inline char Convert2Capital(char _ch)
{
	char ret = 0;
	if ((int)_ch < 123 && (int)_ch > 60) {
		ret = (char)(_ch - 32);
	}
	else {
		ret = _ch;
	}

	return ret;
}

inline bool IsIpFormat(const char* ipStr)
{
    bool isIpFormat = false;
    int len = strlen(ipStr);

    int amountOfDot = 0;
    int amountOfNum = 0;
    for(int i = 0; i < len; i++, ipStr++){
        if(amountOfNum <= 3 &&
           (*ipStr >= (char)48 & *ipStr <= (char)57)){
            amountOfNum = amountOfNum + 1;
        }
        else if(!(*ipStr ^ (char)46)){
            amountOfDot = amountOfDot + 1;
            amountOfNum = 0;
        }
        else{
            isIpFormat = false;
            break;
        }
    }

    if(amountOfDot == 3){
        isIpFormat = true;
    }
    return isIpFormat;
}