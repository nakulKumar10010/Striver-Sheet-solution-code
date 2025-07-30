class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        
        // Queue for BFS: stores current word and number of steps taken to reach it
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // Store all words in an unordered set for O(1) lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Remove the beginWord if present, to avoid revisiting
        st.erase(beginWord);

        while (!q.empty()) {
            // Get the front element from queue
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If we have reached the endWord, return the steps taken
            if (word == endWord)
                return steps;

            // Try changing each character of the current word
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                // Replace with every possible lowercase character
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // If the transformed word exists in the set
                    if (st.find(word) != st.end()) {
                        // Remove it to avoid revisiting
                        st.erase(word);

                        // Push the new word with incremented steps
                        q.push({word, steps + 1});
                    }
                }

                // Restore original character for next iteration
                word[i] = original;
            }
        }

        // If endWord was not reached
        return 0;
    }
};
