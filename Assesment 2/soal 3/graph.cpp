#include "graph.h"
#include <iostream>
#include <queue>
using namespace std;

Graph::Graph() {
}

void Graph::addNode(char id) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->status = "normal";
    newNode->firstEdge = NULL;
    nodes[id] = newNode;
}

void Graph::addEdge(char from, char to) {
    Edge* newEdge = new Edge;
    newEdge->destination = to;
    newEdge->next = nodes[from]->firstEdge;
    nodes[from]->firstEdge = newEdge;
    
    Edge* newEdge2 = new Edge;
    newEdge2->destination = from;
    newEdge2->next = nodes[to]->firstEdge;
    nodes[to]->firstEdge = newEdge2;
}

void Graph::setNodeStatus(char id, string status) {
    if (nodes.find(id) != nodes.end()) {
        nodes[id]->status = status;
    }
}

void Graph::printGraph() {
    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    for (auto& pair : nodes) {
        char nodeId = pair.first;
        Node* node = pair.second;
        
        cout << "Node " << nodeId << " terhubung ke: ";
        
        Edge* edge = node->firstEdge;
        if (edge == NULL) {
            cout << "(tidak ada koneksi)";
        } else {
            while (edge != NULL) {
                cout << edge->destination << " ";
                edge = edge->next;
            }
        }
        cout << endl;
    }
}

void Graph::DFSUtil(char nodeId, map<char, bool>& visited, char excludeNode) {
    if (nodeId == excludeNode) return;
    
    visited[nodeId] = true;
    
    Node* node = nodes[nodeId];
    Edge* edge = node->firstEdge;
    
    while (edge != NULL) {
        if (!visited[edge->destination] && edge->destination != excludeNode) {
            DFSUtil(edge->destination, visited, excludeNode);
        }
        edge = edge->next;
    }
}

bool Graph::isConnected(char excludeNode) {
    map<char, bool> visited;
    
    for (auto& pair : nodes) {
        visited[pair.first] = false;
    }
    
    char startNode = ' ';
    for (auto& pair : nodes) {
        if (pair.first != excludeNode) {
            startNode = pair.first;
            break;
        }
    }
    
    if (startNode == ' ') return true;
    
    DFSUtil(startNode, visited, excludeNode);
    
    for (auto& pair : visited) {
        if (pair.first != excludeNode && !pair.second) {
            return false;
        }
    }
    
    return true;
}

void Graph::analyzeArticulationPoints() {
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)" << endl;
    
    vector<char> articulationPoints;
    
    for (auto& pair : nodes) {
        char nodeId = pair.first;
        
        if (!isConnected(nodeId)) {
            articulationPoints.push_back(nodeId);
            cout << "Kota " << nodeId << " adalah KOTA KRITIS!" << endl;
            cout << "[PERINGATAN] Kota " << nodeId << " adalah KOTA KRITIS!" << endl;
        }
    }
    
    if (articulationPoints.empty()) {
        cout << "Tidak ada kota kritis ditemukan. Jaringan cukup redundan." << endl;
    }
}

void Graph::simulateLockdown(char nodeId) {
    cout << "\n=== Simulasi Lockdown Kota " << nodeId << " ===" << endl;
    
    if (nodes.find(nodeId) == nodes.end()) {
        cout << "Kota " << nodeId << " tidak ditemukan!" << endl;
        return;
    }
    
    string originalStatus = nodes[nodeId]->status;
    nodes[nodeId]->status = "lockdown";
    
    if (isConnected(nodeId)) {
        cout << "Status: Distribusi dapat dilanjutkan ke kota lain." << endl;
        cout << "Kota " << nodeId << " aman (redundansi oke)." << endl;
    } else {
        cout << "Status: Lockdown kota " << nodeId << " memutus distribusi!" << endl;
        cout << "[PERINGATAN] Kota " << nodeId << " adalah KOTA KRITIS!" << endl;
        cout << "Jika kota " << nodeId << " lockdown, distribusi terganggu." << endl;
        
        map<char, bool> visited;
        for (auto& pair : nodes) {
            visited[pair.first] = false;
        }
        
        char startNode = ' ';
        for (auto& pair : nodes) {
            if (pair.first != nodeId) {
                startNode = pair.first;
                break;
            }
        }
        
        if (startNode != ' ') {
            DFSUtil(startNode, visited, nodeId);
            
            cout << "Kota yang masih terjangkau: ";
            for (auto& pair : visited) {
                if (pair.first != nodeId && pair.second) {
                    cout << pair.first << " ";
                }
            }
            cout << endl;
            
            cout << "Kota yang terisolasi: ";
            for (auto& pair : visited) {
                if (pair.first != nodeId && !pair.second) {
                    cout << pair.first << " ";
                }
            }
            cout << endl;
        }
    }
    
    nodes[nodeId]->status = originalStatus;
}