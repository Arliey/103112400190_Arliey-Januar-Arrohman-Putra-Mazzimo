#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>
using namespace std;

struct Edge {
    char destination;
    Edge* next;
};

struct Node {
    char id;
    string status;
    Edge* firstEdge;
};

class Graph {
private:
    map<char, Node*> nodes;
    
    void DFSUtil(char node, map<char, bool>& visited, char excludeNode);
    bool isConnected(char excludeNode);
    
public:
    Graph();
    void addNode(char id);
    void addEdge(char from, char to);
    void setNodeStatus(char id, string status);
    void printGraph();
    void analyzeArticulationPoints();
    void simulateLockdown(char node);
};

#endif