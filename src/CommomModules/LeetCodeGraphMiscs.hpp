#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "StringMiscs.hpp"

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

inline Node* CreateAdjListHelper(int nodeOrder, std::vector<std::vector<std::string>> &list, std::unordered_map<int, Node*> &table)
{
    Node* node = nullptr;
    if(table.find(nodeOrder) != table.end()){
        node = table[nodeOrder];
    }
    else{
        node = new Node(nodeOrder);
        table.insert(std::pair<int, Node*>(nodeOrder, node));
        for(auto n : list[nodeOrder - 1]){
            node->neighbors.push_back(CreateAdjListHelper(std::stoi(n), list, table));
        }
    }
    return node;
}

inline Node* CreateAdjList(std::string g)
{
    // erase "[[" and "]]"
    g.erase(0, 2);
    g.erase(g.size() - 2, 2);

    std::vector<std::string> nodes = SplitString(g, "],[");
    std::vector<std::vector<std::string>> nodeLists;
    for(auto n : nodes){
        nodeLists.push_back(SplitString(n, ","));
    }

	std::unordered_map<int, Node*> table;
    return CreateAdjListHelper(1, nodeLists, table);
}

inline void PrintAdjList(Node* startNode)
{
    std::unordered_map<Node*, bool> visisted;
    std::queue<Node*> nexts;
    nexts.push(startNode);

    std::cout << "{";
    // using BFS
    while(!nexts.empty()){
        Node* cur = nexts.front();
        nexts.pop();

        if(visisted.find(cur) == visisted.end()){
            visisted.insert(std::pair<Node*, bool>(cur, true));

            std::cout << "node " << cur->val << "->";
            size_t len = cur->neighbors.size();
            for(int i = 0; i < len; i++){
                std::cout << cur->neighbors[i]->val;

                if(visisted.find(cur->neighbors[i]) == visisted.end())
                    nexts.push(cur->neighbors[i]);

                if(i < len - 1)
                    std::cout << ", ";
                else
                    std::cout << std::endl;
            }
        }
    }
    std::cout << "}" << std::endl;
}