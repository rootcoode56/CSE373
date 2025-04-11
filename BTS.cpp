#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<string, int> color, d, f;
unordered_map<string, string> previousNode;
int timeCounter = 0;

void DFS_Visit(const string& u, const unordered_map<string, vector<string>>& graph) {
    color[u] = 1; // Grey
    d[u] = ++timeCounter;

    // Check if the node exists in the graph
    if (graph.find(u) != graph.end()) {
        for (const auto& v : graph.at(u)) {
            if (color[v] == 0) { // If the node is white
                previousNode[v] = u;
                DFS_Visit(v, graph);
            }
        }
    }
    color[u] = 2; // Black
    f[u] = ++timeCounter;
}

void DFS(const unordered_map<string, vector<string>>& graph, const string& root) {
    // Initialize all nodes
    for (const auto& node : graph) {
        color[node.first] = 0; // White
        previousNode[node.first] = "NIL";
    }
    DFS_Visit(root, graph);

    // Visit remaining nodes
    for (const auto& node : graph) {
        if (color[node.first] == 0) {
            DFS_Visit(node.first, graph);
        }
    }
}

int main() {
    unordered_map<string, vector<string>> graph = {
        {"CSE115", {"CSE173"}},
        {"CSE173", {"CSE215", "CSE231"}},
        {"CSE215", {"CSE225"}},
        {"CSE225", {"CSE311", "CSE373", "CSE440"}},
        {"CSE231", {"CSE332"}},
        {"CSE311", {"CSE327"}},
        {"CSE332", {"CSE323", "CSE331"}},
        {"CSE327", {"CSE425"}},
        {"CSE440", {"CSE468"}},
        {"CSE299", {}},
        {"CSE499A", {"CSE499B"}},
        {"CSE498R", {}},
        {"CSE495", {}}
    };

    string root = "CSE115";
    DFS(graph, root);

    vector<pair<string, int>> sortedNodes(d.begin(), d.end());
    sort(sortedNodes.begin(), sortedNodes.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    for (const auto& node : sortedNodes) {
        cout << "Node: " << node.first 
             << ", Discovery time: " << node.second 
             << ", Finish time: " << f[node.first] 
             << ", Previous node: " << previousNode[node.first] << "\n";
    }
    return 0;
}