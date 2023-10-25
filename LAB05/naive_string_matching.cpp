#include <bits/stdc++.h>
using namespace std;

// Function for the naive string matching approach
vector<int> naiveApproach(string &text, string &pattern) {
    int n = text.size();
    int m = pattern.size();
    if (n < m)
        return {};  // Return an empty vector if the text is shorter than the pattern.
    vector<int> ans;  // Initialize a vector to store the indices of pattern occurrences.

    // Iterate through the text from the beginning.
    for (int t = 0; t <= n - m; t++) {
        bool is_matched = true;

        // Check if the pattern matches the text starting at index t.
        for (int p = 0; p < m; p++) {
            if (text[t + p] != pattern[p]) {
                is_matched = false;
                break;  // Break if a character mismatch is found.
            }
        }

        // If the pattern is fully matched, add the index t to the result vector.
        if (is_matched) {
            ans.push_back(t);
        }
    }
    return ans;  // Return the vector of pattern occurrences.
}

int main() {
    string str, pattern;
    cout << "Enter the string: ";
    cin >> str;
    cout << "Enter the pattern that you want to find: ";
    cin >> pattern;

    // Call the naiveApproach function to find pattern occurrences in the text.
    vector<int> indices = naiveApproach(str, pattern);

    // Display the indices where the pattern is found in the text.
    for (int i : indices) {
        cout << "Pattern match at index: " << i << "\n";
    }
    return 0;
}
