#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <sstream>

std::string SplitOneData(std::string &str, char delimeter = ',')
{
    if (str == "")
        return "";

    std::ostringstream ss;
    int idx = 0;
    while(str[idx] != delimeter && idx < str.size()) {
        ss << str[idx];
        idx = idx + 1;
    }

    if (str[idx] == ',')
        str = str.substr(idx + 1);
    else
        str = "";

    return ss.str();
}

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

inline std::string ReplaceEscapeCharStr(std::string str)
{
    std::string ret;

    std::function<bool(char)> isEscapeChar =
    [=](char c) -> bool 
    {
        bool _isEscapeChar = false;
        if ('\n' == c) {
            _isEscapeChar = true;
        }
        else if ('\t' == c) {
            _isEscapeChar = true;
        }
        return _isEscapeChar;
    };

    std::function<std::string(char)> convertEscapeChar2Str =
    [=](char c) -> std::string 
    {
        std::string ret = "";
        if ('\n' == c) {
            ret = "\\n";
        }
        else if ('\t' == c) {
            ret = "\\t";
        }
        return ret;
    };

    std::ostringstream ss;
    for (auto c : str) {
        if (isEscapeChar(c))
            ss << convertEscapeChar2Str(c);
        else
            ss << c;
    }

    ret = ss.str();

    return ret;
}

inline std::string RemoveFrontAndEndSquareBracket(std::string str)
{
    std::string res;
    int begin = 0, end = str.size();

    if (str[begin] == '[')
        begin = begin + 1;
    
    if (str[end] == ']')
        end = end - 1;

    res = str.substr(begin, end - begin + 1);
    return res;
}