#ifndef _TEST_STEP_BASE_H_
#define _TEST_STEP_BASE_H_

#include <string>
#include <vector>

class TestStepBase
{
public:
	TestStepBase()
	{}

	virtual ~TestStepBase()
	{}

protected:
	std::vector<std::string> ExecuteScript(void** obj, std::vector<std::string> step, std::vector<std::vector<std::string>> params)
	{
		std::vector<std::string> ret;
		size_t len1 = step.size();
		size_t len2 = params.size();
		if(len1 == len2){
			ret.resize(len1);
			std::vector<std::string>::iterator it = ret.begin();
			for(int i = 0; i < len1; i++){
				*(it + i) = ConductMethod(obj, step.at(i), params.at(i));
			}
			std::cout << std::endl;
		}
		return ret;
	}

	virtual std::string ConductMethod(void** obj, std::string method, std::vector<std::string> param) = 0;
};

#endif // _TEST_STEP_BASE_H_