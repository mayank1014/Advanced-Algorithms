#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum vertex cover of the graph
void minimumVertexCover(vector<vector<int>> &graph, int nodes, int edges) {
    vector<pair<int, int>> edgev(edges);
    vector<int> solution;
    int sum = 0;

    // Create a list of edges (edgev) from the adjacency matrix (graph)
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (1 == graph[i][j]) {
                edgev.push_back({i, j});
            }
        }
    }

    srand(time(NULL)); // Initialize random seed

    int len = edgev.size();
    while (0 <= len) {
        int ri = rand() % len; // Generate a random index
        int u = edgev[ri].first;
        int v = edgev[ri].second;
        solution.push_back(u);
        solution.push_back(v);
        int i = 0;
        while (i < len) {
            if (edgev[i].first == u || edgev[i].first == v || edgev[i].second == u || edgev[i].second == v) {
                sum--;
                len--;
                swap(edgev[i], edgev[len]); // Remove edges incident on u or v
            } else {
                i++;
            }
        }
    }

    cout << "Solution vertex: " << endl;
    for (int v : solution) {
        cout << v << " ";
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    // Create an adjacency matrix (graph) to represent the graph
    vector<vector<int>> graph(nodes, vector<int>(nodes, 0));

    // Input the edges of the graph
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    // Find the minimum vertex cover of the graph
    minimumVertexCover(graph, nodes, edges);
    return 0;
}
