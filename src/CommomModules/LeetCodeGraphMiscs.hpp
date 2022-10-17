#pragma once

#include <vector>
#include <string>
#include <unordered_map>
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

inline Node* CrateAdjList(std::string g)
{
    std::vector<std::string> nodes = SplitString(g, ",");
    std::vector<std::vector<std::string>> nodeLists;
    for(auto n : nodes){
        // erase "[" and "]"
        n.erase(0, 1);
        n.erase(n.size() - 1, 1);

        nodeLists.push_back(SplitString(n, ","));
    }

	std::unordered_map<int, Node*> table;
    return CreateAdjListHelper(1, nodeLists, table);
}

inline void PrintAdjList(Node* startNode)
{
    std::cout << "{";
    // node 1 -> 2, 3
    std::cout << "}" << std::endl;
}