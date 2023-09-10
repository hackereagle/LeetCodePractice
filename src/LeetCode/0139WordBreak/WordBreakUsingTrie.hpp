#pragma once

#include "IWordBreak.hpp"

class WordBreakUsingTrie : public IWordBreak
{
public:
	WordBreakUsingTrie() {}
	~WordBreakUsingTrie() {}
	bool wordBreak(std::string s, std::vector<std::string>& wordDict) override
	{
		TriesNode* tries = CreateTries(wordDict);
        //PrintTries(tries); // debug

        bool canBeBreak = StringCanBeBreak(s, tries);
        delete tries;

        return canBeBreak;
	}

private:
    struct triesNode
    {
        std::unordered_map<char, triesNode*> Nodes;
        bool IsAWordEnd = false;

        triesNode() = default;
        ~triesNode()
        {
            for (auto n : Nodes) {
                if (n.second) {
                    delete n.second;
                    n.second = nullptr;
                }
            }
        }
    };
    typedef struct triesNode TriesNode;
    std::unordered_map<std::string, bool> _dp;

    TriesNode* CreateTries(std::vector<std::string> &wordDict)
    {
        TriesNode* tries = new TriesNode();

        //std::cout << "In CreateTries:" << std::endl; // debug
        TriesNode* curNode = nullptr;
        for (auto w : wordDict) {
            curNode = tries;
            for (int i = 0; i < w.size(); i++) {
                if (curNode->Nodes.find(w[i]) == curNode->Nodes.end()) {
                    curNode->Nodes.insert(std::pair<char, TriesNode*>(w[i], new TriesNode()));
                }
                curNode = curNode->Nodes[w[i]];

                if (i == w.size() - 1) 
                    curNode->IsAWordEnd = true;
            }
        }
        return tries;
    }

    bool StringCanBeBreak(std::string &str, TriesNode* tries)
    {
        if (str == "")
            return true;
        
        bool canBeBreak = false;

        if (_dp.find(str) != _dp.end()) 
            return _dp[str];

        TriesNode* curNode = tries;
        for (int i = 0; i < str.size(); i++) {
            if (curNode->Nodes.find(str[i]) == curNode->Nodes.end()) {
                //std::cout << "In StringCanBeBreak, can not find " << i << "-th word \"" << str[i] << "\"" << std::endl; // debug
                canBeBreak = false;
                _dp.insert(std::pair<std::string, bool>(str, false));
                break;
            }

            curNode = curNode->Nodes[str[i]];
            if (curNode->IsAWordEnd ) {
                //std::cout << "In StringCanBeBreak, " << i << "-th word \"" << str[i] << "\" is end" << std::endl; // debug
                std::string suffix = str.substr(i + 1);
                if (StringCanBeBreak(suffix, tries)) {
                    canBeBreak = true;
                    _dp.insert(std::pair<std::string, bool>(str, true));
                    break;
                }
            }
        }
        
        return canBeBreak;
    }

    void PrintTries(TriesNode* tries, int level = 0)
    {
        std::string space = "";
        if (level > 0) {
            for (int i = 0; i < level; i++)
                space.append("\t");
        }

        for (auto n : tries->Nodes) {
            std::cout << space << n.first << std::endl;
            PrintTries(n.second, level + 1);
        }
    }
};