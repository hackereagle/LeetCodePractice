#ifndef _ASSERT_CLASS_H_
#define _ASSERT_CLASS_H_

#include <iostream>
#include <memory>
#include <stdarg.h>
#include <cmath>

class AssertClass
{
public:
	static AssertClass& GetInstance()
	{
		if(AssertClass::mInstant == nullptr){
			struct temp : AssertClass {};
			AssertClass::mInstant = std::make_unique<temp>();
		}
		return *AssertClass::mInstant;
	}

	void Assert(bool condition, std::string msg = "")
	{
		if(condition){
			std::cout << GRN << "OK:\t" << msg << std::endl;
		}
		else{
			std::cout << RED << "NG:\t" << msg << std::endl;
		}
		std::cout << NC << std::endl;
	}

	void Assert(bool condition, const char* fmt, ...)
	{
		std::string message;
		va_list ap;
		va_start(ap, fmt);
		va2String(message, fmt, &ap);
		va_end(ap);

		if(condition){
			std::cout << GRN << "OK:\t" << message << std::endl;
		}
		else{
			std::cout << RED << "NG:\t" << message << std::endl;
		}
		std::cout << NC << std::endl;
	}

private:
	static std::unique_ptr<AssertClass> mInstant;
	const char* NC = "\e[0m";
	const char* RED = "\e[0;31m";
	const char* GRN = "\e[0;32m";
	const char* CYN = "\e[0;36m";
	const char* REDB = "\e[41m";

	AssertClass()
	{
	}

	void va2String(std::string& str, const char* fmt, ...)
	{
		unsigned int len = 1 << 16;
		char* messageBuff = new char[len];
		va_list ap, *args_dig;
		va_start(ap, fmt);
		args_dig = va_arg(ap, va_list*);
		vsnprintf(messageBuff, len, fmt, *args_dig);
		va_end(ap);
		str = std::string(messageBuff);
		delete [] messageBuff;
	};
};

std::unique_ptr<AssertClass> AssertClass::mInstant;

// refer to https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon
template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    almost_equal(T x, T y, int ulp)
{
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::fabs(x-y) <= std::numeric_limits<T>::epsilon() * std::fabs(x+y) * ulp
        // unless the result is subnormal
        || std::fabs(x-y) < std::numeric_limits<T>::min();
}

inline bool IsTwoDoubleEqual(double r, double l)
{
	return almost_equal(r, l, 15);
}
#endif //_ASSERT_CLASS_H_