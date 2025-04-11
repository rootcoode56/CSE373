#include <iostream>
using namespace std;

// Function to print the adjacency matrix of a complete graph
void printCompleteGraph(int vertices) {
    // Create the adjacency matrix
    int graph[vertices][vertices];

    // Fill the matrix for a complete graph
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                graph[i][j] = 0; // No self-loops
            } else {
                graph[i][j] = 1; // Edge exists between all other vertices
            }
        }
    }

    // Display the adjacency matrix
    cout << "Adjacency Matrix of the Complete Graph:" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices;

    // Input the number of vertices
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // Print the complete graph
    printCompleteGraph(vertices);

    return 0;
}
