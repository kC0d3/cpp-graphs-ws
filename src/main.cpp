#include <iostream>
#include <vector>
#include <unordered_map>
#include "Graph.h"
#include "Node.h"
#include "string"


using namespace std;

int main() {
    Graph friendsGraph;

    friendsGraph.loadFromCSV("data/friends.csv");
    Node* alice = friendsGraph.findNode("Alice");
    std::cout << "Alice baratai: " << std::endl;
    for (Node* friendNode : alice->friends) {
        std::cout << "- " << friendNode->name << std::endl;
    }

    auto circles = friendsGraph.countCircles();
    cout << "Barati korok szama: " << circles << endl;

    const string person1 = "David";
    const string person2 = "Bob";
    auto length = friendsGraph.getLength(person1, person2);
    cout << person1 << " es " << person2  << " kozott " << length << " hosszu ut van";

    return 0;
}