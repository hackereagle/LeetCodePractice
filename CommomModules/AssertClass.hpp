#ifndef _ASSERT_CLASS_H_
#define _ASSERT_CLASS_H_

#include <memory>

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
};

std::unique_ptr<AssertClass> AssertClass::mInstant;
#endif //_ASSERT_CLASS_H_