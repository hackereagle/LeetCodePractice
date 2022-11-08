#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Master {
public:
    Master(std::string goal, unsigned int limit)
    {
        this->mScrete = goal;
        this->mAllowGuess = limit;
        this->mCount = 0;
    }

    int guess(std::string word)
    {
        int ret = 0;
        if (this->mScrete == word){
            if(this->mCount <= this->mAllowGuess){
                std::cout << "You guessed the secret word correctly." << std::endl;
            }
            else {
                std::cout << "Either you took too many guesses, or you did not find the secret word." << std::endl;
            }
            ret = this->mScrete.size();
        }
        else {
            this->mCount++;
            size_t len = 6;
            for(int i = 0; i < len; i++){
                if(this->mScrete[i] == word[i])
                    ret++;
            }
        }
        return ret;
    }

    bool IsAllowTimes()
    {
        return this->mCount <= this->mAllowGuess;
    }

    size_t GuessTimes()
    {
        return this->mCount;
    }

private:
    std::string mScrete;
    int mAllowGuess;
    int mCount;
};

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    ~Solution() {
    }

    Solution() {
    }
    
    void findSecretWord(std::vector<std::string>& words, Master& master) { 
        int score = 0, index = words.size() / 2; 
        while(score < 6){ 
            //std::cout << "words len = " << words.size() << ", index = " << index; 
            score = master.guess(words[index]); 
            //std::cout << ", score = " << score << std::endl; 
            std::vector<std::string> candidate; 
            std::string baseLine = words[index]; 
            if (score == 6){ 
                break; 
            } 
            else { 
                for(auto w : words){ 
                    if (hammingDistanceWithS1(baseLine, w) == score) 
                        candidate.push_back(w); 
                } 
                 
                words = candidate; 
                index = words.size() / 2; 
            } 
        } 
    }

private: 
    int hammingDistanceWithS1(std::string s1, std::string s2) 
    { 
        int hammingDist = 0; 
        for(int i = 0; i < 6; i++){ 
            //if (!(s1[i] ^ s2[i])) 
            if (s1[i] == s2[i]) 
                hammingDist++; 
        } 
        return hammingDist; 
    }
};



class TestFindSecretWord
{
public:
	TestFindSecretWord()
	{}

	~TestFindSecretWord()
	{}
	
	void Example1()
	{
        std::cout << "========= Example 1 =========" << std::endl;
        std::string secret = "acckzz";
		std::vector<std::string> words({"acckzz","ccbazz","eiowzz","abcczz"});
        int allowedGuesses = 10;
        Master master(secret, allowedGuesses);

        int len = words.size();
		this->mSolution.findSecretWord(words, master);
        std::cout << "total words = " << len << ", guess times = " << master.GuessTimes() << std::endl;
		AssertClass::GetInstance().Assert(master.IsAllowTimes());
	}

	void Example2()
	{
        std::cout << "========= Example 2 =========" << std::endl;
        std::string secret = "hamada";
		std::vector<std::string> words({"hamada","khaled"});
        int allowedGuesses = 10;
        Master master(secret, allowedGuesses);

        int len = words.size();
		this->mSolution.findSecretWord(words, master);
        std::cout << "total words = " << len << ", guess times = " << master.GuessTimes() << std::endl;
		AssertClass::GetInstance().Assert(master.IsAllowTimes());
	}

	void Example3()
	{
        std::cout << "========= Example 3 =========" << std::endl;
        std::string secret = "hbaczn";
		std::vector<std::string> words({"gaxckt","trlccr","jxwhkz","ycbfps","peayuf","yiejjw","ldzccp","nqsjoa","qrjasy","pcldos","acrtag","buyeia","ubmtpj","drtclz","zqderp","snywek","caoztp","ibpghw","evtkhl","bhpfla","ymqhxk","qkvipb","tvmued","rvbass","axeasm","qolsjg","roswcb","vdjgxx","bugbyv","zipjpc","tamszl","osdifo","dvxlxm","iwmyfb","wmnwhe","hslnop","nkrfwn","puvgve","rqsqpq","jwoswl","tittgf","evqsqe","aishiv","pmwovj","sorbte","hbaczn","coifed","hrctvp","vkytbw","dizcxz","arabol","uywurk","ppywdo","resfls","tmoliy","etriev","oanvlx","wcsnzy","loufkw","onnwcy","novblw","mtxgwe","rgrdbt","ckolob","kxnflb","phonmg","egcdab","cykndr","lkzobv","ifwmwp","jqmbib","mypnvf","lnrgnj","clijwa","kiioqr","syzebr","rqsmhg","sczjmz","hsdjfp","mjcgvm","ajotcx","olgnfv","mjyjxj","wzgbmg","lpcnbj","yjjlwn","blrogv","bdplzs","oxblph","twejel","rupapy","euwrrz","apiqzu","ydcroj","ldvzgq","zailgu","xgqpsr","wxdyho","alrplq","brklfk"});
        int allowedGuesses = 10;
        Master master(secret, allowedGuesses);

        int len = words.size();
		this->mSolution.findSecretWord(words, master);
        std::cout << "total words = " << len << ", guess times = " << master.GuessTimes() << std::endl;
		AssertClass::GetInstance().Assert(master.IsAllowTimes());
	}

	void Example4()
	{
        std::cout << "========= Example 4 =========" << std::endl;
        std::string secret = "ccoyyo";
		std::vector<std::string> words({"wichbx","oahwep","tpulot","eqznzs","vvmplb","eywinm","dqefpt","kmjmxr","ihkovg","trbzyb","xqulhc","bcsbfw","rwzslk","abpjhw","mpubps","viyzbc","kodlta","ckfzjh","phuepp","rokoro","nxcwmo","awvqlr","uooeon","hhfuzz","sajxgr","oxgaix","fnugyu","lkxwru","mhtrvb","xxonmg","tqxlbr","euxtzg","tjwvad","uslult","rtjosi","hsygda","vyuica","mbnagm","uinqur","pikenp","szgupv","qpxmsw","vunxdn","jahhfn","kmbeok","biywow","yvgwho","hwzodo","loffxk","xavzqd","vwzpfe","uairjw","itufkt","kaklud","jjinfa","kqbttl","zocgux","ucwjig","meesxb","uysfyc","kdfvtw","vizxrv","rpbdjh","wynohw","lhqxvx","kaadty","dxxwut","vjtskm","yrdswc","byzjxm","jeomdc","saevda","himevi","ydltnu","wrrpoc","khuopg","ooxarg","vcvfry","thaawc","bssybb","ccoyyo","ajcwbj","arwfnl","nafmtm","xoaumd","vbejda","kaefne","swcrkh","reeyhj","vmcwaf","chxitv","qkwjna","vklpkp","xfnayl","ktgmfn","xrmzzm","fgtuki","zcffuv","srxuus","pydgmq"});
        int allowedGuesses = 10;
        Master master(secret, allowedGuesses);

        int len = words.size();
		this->mSolution.findSecretWord(words, master);
        std::cout << "total words = " << len << ", guess times = " << master.GuessTimes() << std::endl;
		AssertClass::GetInstance().Assert(master.IsAllowTimes());
	}

private:
    Solution mSolution;
};

int main(int argc, char** argv)
{
	TestFindSecretWord test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}