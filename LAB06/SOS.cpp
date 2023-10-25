#include <bits/stdc++.h>
using namespace std;

int n;

bool dynamic_knapsack(int p[], int w[], int c, int v) {
    vector<vector<int>> mat(n + 1, vector<int>(c + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (w[i - 1] <= j)
                mat[i][j] = max(mat[i - 1][j], p[i - 1] + mat[i - 1][j - w[i - 1]]);
            else
                mat[i][j] = mat[i - 1][j];
        }
    }
    
    if(mat[n][c] == v)
       return true;
    
    else
       return false;

   
}

int main() {
    cout << "Enter length of array: " << endl;
    cin >> n;
    int array[n], profit[n], weight[n];
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << "Enter sum: " << endl;
    int sum;
    cin >> sum;

    int capacity, assumed_profit;
    for (int i = 0; i < n; i++) {
        profit[i] = array[i];
        weight[i] = array[i];
    }

    capacity = sum;
    assumed_profit = sum;

    if (dynamic_knapsack(profit, weight, capacity, assumed_profit))
        cout << "True";
    else
        cout << "False";

return 0;
}
