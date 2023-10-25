#include <bits/stdc++.h>  // Includes the necessary header files for standard input/output and data structures.

using namespace std;

void find_min_cut(int n, int g[4][4]) {
    int g1[n][n];  // Define a 2D array 'g1' to store the updated graph.

    // The while loop begins for the Karger's Min Cut algorithm.
    while (n > 2) {  // Continue as long as there are more than 2 vertices in the graph.

        int u, v;  // Initialize variables to store the vertices to contract.

        cout << "Enter u";  // Prompt the user to enter vertex 'u'.
        cin >> u;  // Read the input vertex 'u'.

        cout << "Enter v";  // Prompt the user to enter vertex 'v'.
        cin >> v;  // Read the input vertex 'v'.

        int cnt = 0;  // Initialize a counter for edges.

        // Loop through all pairs of vertices in the graph.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                cnt = 0;  // Reset the edge counter.

                // Check if the current edge involves vertices 'u' and 'v'.
                if (i == u && j == v) {
                    g1[i][j] = 0;  // Set the edge weight between 'u' and 'v' to 0.
                    g1[j][i] = 0;  // Set the reverse edge weight to 0 (undirected graph).
                }

                // Check if the current vertex is 'u' or 'v'.
                else if (i == u || i == v) {
                    if (g[u][j] > 0) {
                        cnt += g[u][j];  // Update the edge weight with 'u'.
                    }

                    if (g[v][j] > 0) {
                        cnt += g[v][j];  // Update the edge weight with 'v'.
                    }

                    if (u < j) {
                        g1[u][j] = cnt;  // Update the edge weight in 'g1' (either [u][j] or [j][u]).
                    } else {
                        g1[j][u] = cnt;  // Update the edge weight in 'g1' (either [j][u] or [u][j]).
                    }

                    if (v < j) {
                        g1[v][j] = cnt;  // Update the edge weight in 'g1' (either [v][j] or [j][v]).
                    } else {
                        g1[j][v] = cnt;  // Update the edge weight in 'g1' (either [j][v] or [v][j]).
                    }
                }

                // Check if the current vertex is 'u' or 'v'.
                else if (j == u || j == v) {
                    if (g[u][i] > 0) {
                        cnt += g[u][i];  // Update the edge weight with 'u'.
                    }

                    if (g[v][i] > 0) {
                        cnt += g[v][i];  // Update the edge weight with 'v'.
                    }

                    if (u < i) {
                        g1[u][i] = cnt;  // Update the edge weight in 'g1' (either [u][i] or [i][u]).
                    } else {
                        g1[i][u] = cnt;  // Update the edge weight in 'g1' (either [i][u] or [u][i]).
                    }

                    if (v < i) {
                        g1[v][i] = cnt;  // Update the edge weight in 'g1' (either [v][i] or [i][v]).
                    } else {
                        g1[i][v] = cnt;  // Update the edge weight in 'g1' (either [i][v] or [v][i]).
                    }
                } else {
                    g1[i][j] = g[i][j];  // If none of the above conditions are met, copy the edge weight.
                }
            }
        }

        // The code then symmetrizes the graph by ensuring g1[i][j] == g1[j][i].
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    g1[i][j] = g1[j][i];
                }
            }
        }

        int g2[n - 1][n - 1];  // Define a smaller graph 'g2' with one less vertex and update it.

        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (i == v)
                continue;
            b = 0;
            for (int j = 0; j < n; j++) {
                if (j == v)
                    continue;
                else {
                    g2[a][b] = g1[i][j];  // Copy the updated edge weights to 'g2'.
                    b++;
                }
            }
            a++;
        }

        // Finally, copy the updated 'g2' back to 'g' with one less vertex.
        for (int i = 0; i < (n - 1); i++) {
            for (int j = 0; j < (n - 1); j++) {
                g[i][j] = g2[i][j];
            }
        }

        n = n - 1;  // Decrement the number of vertices as one vertex was merged into another.
    }

    int cut_value = g[0][1];  // Calculate and store the minimum cut value in the remaining graph.

    cout << "Min cut is : " << cut_value;  // Print the minimum cut value to the console.
}

int main() {
    // Define a 4x4 matrix 'arr' to represent the initial graph.
    int arr[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    find_min_cut(4, arr);  // Call the 'find_min_cut' function with the graph and its size.

    return 0;  // Return 0 to indicate successful program execution.
}
