#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
    Solution()
    {}

    ~Solution()
    {}

    bool validUtf8(std::vector<int>& data) {
        bool isValidUtf8 = true;

        size_t len = data.size();
        for (int i = 0; i < len;) {
            //std::cout << i << std::endl;
            int num = CheckingRepresentByteNum(data[i]);
            //std::cout << "\tnum = " << num << std::endl;
            if (num == -1 || num == 1) {
                isValidUtf8 = false;
                break;
            }
            else if (1 < num && num <= 4){
                if (i + num - 1 >= len) {
                    isValidUtf8 = false;
                    break;
                }

                i = i + 1;
                for (int j = 0; j < num - 1; j++, i++) {
                    int temp = data[i] >> 6;
                    //std::cout << "\t" << i << ", temp = " << temp << std::endl;
                    if (temp != 2) {
                        isValidUtf8 = false;
                        break;
                    }
                }
            }
            else {
                i++;
            }
        }
        return isValidUtf8;
    }

private:
    int CheckingRepresentByteNum(int prifix)
    {
        int ret = -1;

        int i = 0;
        for (; i < 5; i++) {
            //std::cout << "\tIn CheckingRepresentByteNum, i = " << i << std::endl;
            int bit = prifix >> (7 - i);
            //std::cout << "\tIn CheckingRepresentByteNum, bit = " << (unsigned int)bit << std::endl;
            bit = bit & 1;
            //std::cout << "\tIn CheckingRepresentByteNum, after operate, bit = " << bit << std::endl;
    
            if (bit == 0)
                break;
        }

        if (i <= 4)
            ret = i;

        return ret;
    }
};

class TestValidUtf8
{
public:
	TestValidUtf8()
	{}

	~TestValidUtf8()
	{}

    void Input_197_130_1_Output_true()
    {
        std::cout << "Test input [197,130,1] and output true" << std::endl;;
        std::vector<int> input({197, 130, 1});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == true);
    }

    void Input_235_140_4_Output_false()
    {
        std::cout << "Test input [235,140,4] and output false" << std::endl;;
        std::vector<int> input({235,140,4});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == false);
    }

    void Input_237_Output_false()
    {
        std::cout << "Test input [237] and output false" << std::endl;;
        std::vector<int> input({237});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == false);
    }

    void Input_230_136_145_Output_true()
    {
        std::cout << "Test input [230,136,145] and output true" << std::endl;;
        std::vector<int> input({230,136,145});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == true);
    }

    void Input_145_Output_false()
    {
        std::cout << "Test input [145] and output false" << std::endl;;
        std::vector<int> input({145});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == false);
    }

    void Input_240_162_138_147_Output_true()
    {
        std::cout << "Test input [240, 162, 138, 147] and output true" << std::endl;;
        std::vector<int> input({240, 162, 138, 147});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == true);
    }

    void Input_248_130_130_130_Output_true()
    {
        std::cout << "Test input [240, 162, 138, 147] and output true" << std::endl;;
        std::vector<int> input({240, 162, 138, 147});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == true);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestValidUtf8 test;
    test.Input_197_130_1_Output_true();
    test.Input_235_140_4_Output_false();
    test.Input_237_Output_false();
    test.Input_230_136_145_Output_true();
    test.Input_145_Output_false();
    test.Input_240_162_138_147_Output_true();
    test.Input_248_130_130_130_Output_true();
	getchar();
	return EXIT_SUCCESS;
}