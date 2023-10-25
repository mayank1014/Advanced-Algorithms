#include <bits/stdc++.h>
using namespace std;
#define d 256

void rabinKarp(string pat, string txt, int q)
{
    int M = pat.length();  // Length of the pattern.
    int N = txt.length();  // Length of the text.
    int i, j;
    int p = 0;  // Hash value for the pattern.
    int t = 0;  // Hash value for the current text window.
    int h = 1;  // A constant to be used in hash calculation.
    bool found = 0;  // Flag to track whether the pattern is found.
    int hits = 0;  // Count of successful pattern hits.

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;  // Precompute (d^(M-1)) % q for rolling hash.

    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;  // Calculate the hash value for the pattern.
        t = (d * t + txt[i]) % q;  // Calculate the hash value for the initial text window of size M.
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)  // Compare hash values.
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;  // If there's a character mismatch, break the loop.
            }

            if (j == M)
            {
                cout << "Pattern found at index " << i << endl;  // Pattern found at position 'i' in the text.
                found = 1;
            }
            hits++;  // Increment the hit count for matching hash values.
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;  // Update the hash value for the next text window.
            if (t < 0)
                t = (t + q);  // Ensure the hash value is non-negative.
        }
    }

    if (!found)
        cout << "Pattern not found" << endl;

    cout << "Total number of hits when the hash values were the same: " << hits << endl;
}

int main()
{
    string text, pattern;
    int q;  // Mode value used in the Rabin-Karp algorithm.
    cout << "Enter Your TEXT: ";
    cin >> text;
    cout << "Enter pattern to search: ";
    cin >> pattern;
    cout << "Enter the value of q: ";
    cin >> q;

    rabinKarp(pattern, text, q);  // Call the Rabin-Karp search function.

    return 0;
}
