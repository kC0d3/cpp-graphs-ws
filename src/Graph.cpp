#include "Graph.h"
#include "Node.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <unordered_map>

void Graph::loadFromCSV(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string node1, node2;
        std::getline(ss, node1, ',');
        std::getline(ss, node2, ',');

        Node *n1 = findNode(node1);
        Node *n2 = findNode(node2);

        n1->friends.push_back(n2);
        n2->friends.push_back(n1);
    }
}

Node *Graph::findNode(const std::string &name)
{
    for (Node *node : nodes)
    {
        if (node->name == name)
        {
            return node;
        }
    }

    auto *newNode = new Node(name);
    nodes.push_back(newNode);
    return newNode;
}

int Graph::countCircles() {
    std::unordered_set<Node*> visited;
    int circles = 0;

    for (Node* node : nodes) {
        if (visited.count(node) == 0) {
            circles++;
            DFS(node, visited);
        }
    }
    return circles;
}

void Graph::DFS(Node* node, std::unordered_set<Node*>& visited) {
    visited.insert(node);
    for (Node* f : node->friends) {
        if (visited.count(f) == 0) {
            DFS(f, visited);
        }
    }
}

int Graph::BFS(const std::string& startName, const std::string& endName) {
    Node* start = findNode(startName);
    Node* end = findNode(endName);

    if (!start || !end) {
        return -1; // Egyik vagy másik csúcs nem található
    }

    std::unordered_map<Node*, int> distance;
    std::queue<Node*> q;

    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current == end) {
            return distance[current];
        }

        for (Node* neighbor : current->friends) {
            if (distance.find(neighbor) == distance.end()) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    return -1;
}

int Graph::getLength(const std::string &startName, const std::string &endName) {
    return BFS(startName, endName);
}

