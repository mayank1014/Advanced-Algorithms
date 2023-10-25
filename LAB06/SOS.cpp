#include <bits/stdc++.h>
using namespace std;

int n;

// Function to solve the knapsack problem
bool dynamic_knapsack(int p[], int w[], int c, int v) {
    vector<vector<int>> mat(n + 1, vector<int>(c + 1, 0));

    // Dynamic programming loop to fill the matrix mat
    for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= c; j++) {
        if (w[i - 1] <= j) {
            // If the weight of the current item (at index i - 1) is less than or equal to the remaining capacity (j):
            // We have two choices:
            // 1. Exclude the current item (i - 1), so the value remains the same as for the previous item at the same capacity.
            // 2. Include the current item (i - 1), adding its profit to the maximum value obtained with the remaining capacity
            // after subtracting the weight of the current item.
            // We choose the option that results in a higher profit and store it in the matrix.
            mat[i][j] = max(mat[i - 1][j], p[i - 1] + mat[i - 1][j - w[i - 1]]);
        } else {
            // If the weight of the current item is greater than the remaining capacity:
            // We can't include the current item, so we simply inherit the value obtained
            // by considering the previous items with the same capacity.
            mat[i][j] = mat[i - 1][j];
        }
    }
}


    // If the value in the matrix at cell (n, c) matches the assumed profit (v), return true.
    if (mat[n][c] == v)
        return true;
    else
        return false;
}

int main() {
    cout << "Enter the length of the array: " << endl;
    cin >> n;
    int array[n], profit[n], weight[n];

    cout << "Enter array elements (profits and weights): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "Enter the assumed profit value: " << endl;
    int assumed_profit;
    cin >> assumed_profit;

    cout << "Enter the knapsack capacity: " << endl;
    int capacity;
    cin >> capacity;

    // Split the input array into profit and weight arrays
    for (int i = 0; i < n; i++) {
        profit[i] = array[i];
        weight[i] = array[i];
    }

    // Check if it's possible to achieve the assumed profit value with the given capacity
    if (dynamic_knapsack(profit, weight, capacity, assumed_profit))
        cout << "True";
    else
        cout << "False";

    return 0;
}
