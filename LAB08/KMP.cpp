#include <bits/stdc++.h>
using namespace std;

int m, n; // Declare global variables to store the sizes of the pattern and input string.

void string_matching(string s, string p, int lps[]) {
    int q = 0; // Initialize a state variable q for pattern matching.

    cout << "Pattern occurred at indexes : "; // Print a message indicating where the pattern was found.

    for (int i = 1; i <= n; i++) {
        while (q > 0 && p[q] != s[i - 1]) {
            q = lps[q]; // Adjust the state q based on the Longest Prefix Suffix (lps) value.
        }

        if (p[q] == s[i - 1]) {
            q++; // Increment the state q if there's a match with the pattern character.
        }

        if (q == m) {
            cout << i - m << " "; // If the state q matches the pattern length, print the starting index of the pattern.
            q = lps[q]; // Adjust the state q based on the lps value.
        }
    }
}

int main() {
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;
    n = s.size(); // Read the input string and store its size in the variable n.

    string pattern;
    cout << "Enter pattern : " << endl;
    cin >> pattern;
    m = pattern.size(); // Read the pattern and store its size in the variable m.

    // Preprocessing for generating the Longest Prefix Suffix (lps) table.
    int p_table[m + 1]; // Create an array to store lps values. Initialize it with size m + 1.
    p_table[1] = 0; // Initialize the first element of the lps table to 0.
    int k = 0; // Initialize a variable k.

    for (int q = 2; q <= m; q++) {
        while (k > 0 && pattern[k] != pattern[q - 1]) {
            k = p_table[k]; // Adjust k based on previous lps values.
        }

        if (pattern[k] == pattern[q - 1]) {
            k++; // Increment k if there's a match between pattern characters.
        }

        p_table[q] = k; // Store the calculated lps value for position q.
    }

    // Call the string_matching function with the input string, pattern, and lps table.
    string_matching(s, pattern, p_table);

    return 0;
}

// TestCase:
// String: ababcabcabababd
// Pattern: ababd

// Prefix table: 0 0 1 2 0 
