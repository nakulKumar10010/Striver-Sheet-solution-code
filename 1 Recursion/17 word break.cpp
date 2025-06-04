#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> st;  // Set to store dictionary words for O(1) lookup
    int n;                     // Length of the input string

    // Recursive function to check if s[idx:] can be segmented
    bool solve(int idx, string& s) {
        // Base Case: If we've reached the end of the string, return true
        if (idx >= n) return true;

        //if we find the word directly
        if(st.find(s) != st.end()) return true;

        // Try every possible substring starting from idx
        for (int l = 1; idx + l <= n; l++) {
            string temp = s.substr(idx, l);  // Take substring from idx of length l

            // If this prefix exists in the dictionary and the rest of the string can be segmented
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return true;
            }
        }

        // If no valid segmentation is found
        return false;
    }

    // Main function
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();  // Store length of the input string

        // Insert all dictionary words into the unordered_set
        for (string& word : wordDict) {
            st.insert(word);
        }

        // Start recursive checking from index 0
        return solve(0, s);
    }
};

/************************************************************************************************************************************************/
//MEMORIZATION DP

