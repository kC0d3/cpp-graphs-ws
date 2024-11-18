#pragma once
#include <vector>
#include <string>
#include "Node.h"
#include <unordered_set>

class Graph {
public:
    std::vector<Node*> nodes;
    void loadFromCSV(const std::string& filename);
    Node* findNode(const std::string& name);
    int countCircles();
    int getLength(const std::string& startName, const std::string& endName);
private:
    void DFS(Node* node, std::unordered_set<Node*>& visited);
    int BFS(const std::string& startName, const std::string& endName);
};