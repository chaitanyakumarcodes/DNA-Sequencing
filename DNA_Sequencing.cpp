#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to find the longest common subsequence of two DNA sequences
string longestCommonSubsequence(const string& sequence1, const string& sequence2) {
    int m = sequence1.length();
    int n = sequence2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (sequence1[i - 1] == sequence2[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the longest common subsequence
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (sequence1[i - 1] == sequence2[j - 1])
        {
            lcs = sequence1[i - 1] + lcs;
            i--;
            j--;
        } 
        else 
        {
            if (dp[i - 1][j] > dp[i][j - 1]) 
            {
                i--;
            } 
            else 
            {
                j--;
            }
        }
    }
 
    return lcs;
}

// Function to identify point mutations (substitutions) in DNA sequences
void identifyMutations(const string& sequence1, const string& sequence2) {
    if (sequence1.length() != sequence2.length()) {
        cout << "Error: Sequences must have the same length for mutation analysis.\n";
        return;
    }

    int numMutations = 0;
    for (size_t i = 0; i < sequence1.length(); i++) {
        if (sequence1[i] != sequence2[i]) {
            cout << "Mutation at position " << i + 1 << ": " << sequence1[i] << " -> " << sequence2[i] << endl;
            numMutations++;
        }
    }

    if (numMutations == 0) {
        cout << "No mutations found.\n";
    }
}

int main() {
    string sequence1, sequence2;

    cout << "Enter the first DNA sequence: ";
    cin >> sequence1;

    cout << "Enter the second DNA sequence: ";
    cin >> sequence2;

    // Finding the longest common subsequence
    string lcs = longestCommonSubsequence(sequence1, sequence2);
    cout << "Longest Common Subsequence: " << lcs << endl;

    // Identifying mutations
    identifyMutations(sequence1, sequence2);
    
    return 0;
}