#ifndef _ASSERT_CLASS_H_
#define _ASSERT_CLASS_H_

#include <iostream>
#include <memory>
#include <stdarg.h>

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
#endif //_ASSERT_CLASS_H_