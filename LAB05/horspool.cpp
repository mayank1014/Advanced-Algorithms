#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 256;

// Function to preprocess the shift table for pattern matching
vector<int> preprocessShiftTable(string pattern) {
    int m = pattern.length();
    // Initialize the shift table with a default shift value of m (pattern length)
    vector<int> shiftTable(ALPHABET_SIZE, m);

    // Fill in the shift table based on the pattern
    for (int i = 0; i < m - 1; i++) {
        // Calculate the shift value for the character at pattern[i]
        shiftTable[pattern[i]] = m - 1 - i;
    }

    return shiftTable;
}

// Function to search for the pattern in the text using the Horspool algorithm
void horsepoolSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    // Preprocess the shift table
    vector<int> shiftTable = preprocessShiftTable(pattern);

    // Initialize the text index to the end of the pattern
    int i = m - 1;
    // Search for the pattern in the text
    while (i < n) {
        int k = 0;
        // Compare characters from right to left in the pattern
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }

        // If k equals the pattern length, a match is found
        if (k == m) {
            cout << "Pattern found at index " << i - m + 1 << endl;
        }

        // Use the shift table to determine the next position to compare
        i += shiftTable[text[i]];
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern to search: ";
    cin >> pattern;

    // Call the function to search for the pattern in the text
    horsepoolSearch(text, pattern);

    return 0;
}

//TestCase
// Text: JIM_SAW_ME_IN_A_BARBER_SHOP
// Pattern: BARBER

// Table: 
// B : 2
// A : 4
// R : 6
// E : 1
