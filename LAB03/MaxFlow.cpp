#include <bits/stdc++.h>

#define n 6
using namespace std;

// Function to perform Breadth-First Search (BFS) to find augmenting paths in the residual graph.
bool bfs(int rgraph[n][n], int s, int t, int parent[]) {
	int visited[n] = {0}; // Initialize an array to keep track of visited vertices.
	queue<int> q; // Create a queue for BFS.
	q.push(s); // Start the BFS from the source vertex.
	visited[s] = 1; // Mark the source vertex as visited.
	parent[s] = -1; // Set the parent of the source vertex to -1.

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		// Explore adjacent vertices in the residual graph.
		for (int v = 0; v < n; v++) {
			if (visited[v] == 0 && rgraph[u][v] > 0) {
				if (v == t) {
					parent[v] = u;
					return true; // If the sink vertex is reached, an augmenting path is found.
				}

				q.push(v);
				visited[v] = 1;
				parent[v] = u;
			}
		}
	}

	return false; // If no augmenting path is found, return false.
}

// Function to implement the Ford-Fulkerson algorithm.
int fordFulkerson(int g[n][n], int s, int t) {
	int rgraph[n][n];

	// Create a residual graph and initialize it with the original graph.
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			rgraph[u][v] = g[u][v];
		}
	}

	int parent[n]; // Create an array to store the parent vertices.
	int max_flow = 0; // Initialize the maximum flow.

	// While there is an augmenting path, update the residual graph and the maximum flow.
	while (bfs(rgraph, s, t, parent)) {
		int path_flow = INT_MAX;

		// Find the minimum capacity (flow) along the augmenting path.
		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v];
			path_flow = min(path_flow, rgraph[u][v]);
		}

		// Update the residual graph with the new flow values.
		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v];
			rgraph[u][v] -= path_flow;
			rgraph[v][u] += path_flow;
		}

		max_flow += path_flow; // Update the maximum flow.
	}

	return max_flow; // Return the maximum flow.
}

int main() {
	int g[n][n] = {
		{0, 16, 13, 0, 0, 0},
		{0, 0, 10, 12, 0, 0},
		{0, 4, 0, 0, 14, 0},
		{0, 0, 9, 0, 0, 20},
		{0, 0, 0, 7, 0, 4},
		{0, 0, 0, 0, 0, 0}
	};

	int max_flow = fordFulkerson(g, 0, 5); // Find the maximum flow from source (0) to sink (5).
	cout << "Max flow is: " << max_flow; // Print the maximum flow value.

	return 0;
}
