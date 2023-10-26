#include <iostream>
#include <vector>

class VCP {
private:
    int V;  // Number of vertices in the graph

public:
    VCP(int v) {
        V = v;  // Initialize the number of vertices
    }

    void printVertexCover(std::vector<std::vector<int>> &g) {
        std::vector<bool> visited(V, false);  // Initialize a vector to track visited vertices

        // Iterate over each vertex in the graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {  // If vertex i is unvisited
                // Check all other vertices to find an edge (i, j) where j is unvisited
                for (int j = 0; j < V; j++) {
                    if (g[i][j] == 1 && !visited[j]) {  // If an edge is found
                        visited[i] = true;  // Mark vertex i as visited
                        visited[j] = true;  // Mark vertex j as visited
                        break;  // Move on to the next unvisited vertex
                    }
                }
            }
        }

        std::cout << std::endl;

        // Iterate over all vertices and print those that are part of the minimum vertex cover
        for (int j = 0; j < V; j++) {
            if (visited[j]) {
                std::cout << j << " ";  // Print the index of the visited vertex
            }
        }

        std::cout << std::endl;
    }
};

int main() {
    VCP g(4);  // Create an instance of the VCP class with 4 vertices

    // Define the graph using an adjacency matrix
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    std::cout << std::endl;

    // Call the printVertexCover function to find and print the minimum vertex cover
    g.printVertexCover(graph);

    std::cout << std::endl;

    return 0;
}
