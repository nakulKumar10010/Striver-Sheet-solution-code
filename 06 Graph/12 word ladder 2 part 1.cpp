class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        // Create a set of all words in the wordList for fast lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Queue for BFS, storing transformation sequences
        queue<vector<string>> q;
        q.push({beginWord}); // Start with the beginWord

        // Track words used at the current BFS level
        vector<string> usedOnlevel;
        usedOnlevel.push_back(beginWord);

        int level = 0; // Track current level (length of transformation path)
        vector<vector<string>> ans; // Final result storing shortest transformation sequences

        while (!q.empty()) {
            vector<string> vec = q.front(); // Get the current path
            q.pop();

            // If we reach a new level, remove all words used in the previous level from the set
            if (vec.size() > level) {
                level++;
                for (auto it : usedOnlevel) {
                    st.erase(it); // Prevent revisiting the same word in another path
                }
                usedOnlevel.clear();
            }

            string word = vec.back(); // Get the last word in the current path

            // If we reached the endWord, consider this path for the answer
            if (word == endWord) {
                // If it's the first valid path, add it directly
                if (ans.size() == 0) {
                    ans.push_back(vec);
                } 
                // If it's the same length as the first shortest path, add it as well
                else if (ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }

            // Try all possible single-character transformations
            for (int i = 0; i < word.size(); i++) {
                char original = word[i]; // Save original character
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c; // Change character at position i

                    // If the transformed word exists in the set, it's a valid move
                    if (st.count(word) > 0) {
                        vec.push_back(word); // Add new word to current path
                        q.push(vec);         // Enqueue the new path
                        usedOnlevel.push_back(word); // Mark word as used on this level
                        vec.pop_back();      // Backtrack for next transformation
                    }
                }
                word[i] = original; // Restore original word for next character position
            }
        }

        return ans; // Return all shortest transformation sequences
    }
};
