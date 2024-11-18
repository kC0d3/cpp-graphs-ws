#pragma once
#include <vector>
#include <string>

class Node {
public:
    std::string name;
    std::vector<Node*> friends;

    Node(const std::string& name) : name(name) {}
};