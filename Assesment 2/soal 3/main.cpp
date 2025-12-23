#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph vaksinGraph;
    cout << "ANALISIS JARINGAN DISTRIBUSI VAKSIN" << endl;
    
    vaksinGraph.addNode('A');
    vaksinGraph.addNode('B');
    vaksinGraph.addNode('C');
    vaksinGraph.addNode('D');
    vaksinGraph.addNode('E');
    
    vaksinGraph.addEdge('A', 'B');
    vaksinGraph.addEdge('B', 'C');
    vaksinGraph.addEdge('C', 'A');
    vaksinGraph.addEdge('C', 'D');
    vaksinGraph.addEdge('D', 'E');
    vaksinGraph.addEdge('E', 'C');
    
    vaksinGraph.printGraph();
    vaksinGraph.analyzeArticulationPoints();
    
    vaksinGraph.simulateLockdown('A');
    vaksinGraph.simulateLockdown('B');
    vaksinGraph.simulateLockdown('C');
    vaksinGraph.simulateLockdown('D');
    vaksinGraph.simulateLockdown('E');

    cout << "PROGRAM SELESAI" << endl;
    
    return 0;
}