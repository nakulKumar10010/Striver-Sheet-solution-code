// ------------------ Node Structure ------------------
// Each Node represents one character in the Trie
// links[26] -> pointers to next characters (a-z)
// flag -> true if this node marks the end of a word
struct Node {
    Node* links[26];
    bool flag = false;
};

// ------------------ Trie Class ------------------
class Trie {
private:
    Node* root; // root node of the Trie

public:
    // Constructor -> creates an empty Trie with root node
    Trie() {
        root = new Node();
    }

    // Insert a word into the Trie
    void insert(string word) {
        Node* node = root;
        for (auto& it : word) {
            // if character doesn't exist, create a new node
            if (node->links[it - 'a'] == NULL) {
                node->links[it - 'a'] = new Node();
            }
            // move to the next node
            node = node->links[it - 'a'];
        }
        // after inserting all characters, mark word end
        node->flag = true;
    }

    // Check if all prefixes of a word exist in the Trie
    bool checkPrefixExits(string word) {
        Node* node = root;
        for (auto& it : word) {
            // if link exists, move forward
            if (node->links[it - 'a'] != NULL) {
                node = node->links[it - 'a'];

                // if prefix till now is NOT a word, fail
                if (node->flag == false) {
                    return false;
                }
            }
            // if link doesn't exist -> prefix broken
            else {
                return false;
            }
        }
        // all prefixes exist -> return true
        return true;
    }
};

// ------------------ Solution Class ------------------
class Solution {
public:
    // Function to find the longest word where every prefix is also a word
    string longestValidWord(vector<string>& words) {
        Trie trie;

        // Step 1: Insert all words into Trie
        for (auto& it : words) {
            trie.insert(it);
        }

        string longest = "";

        // Step 2: Check each word
        for (auto& it : words) {
            // If all prefixes of this word exist
            if (trie.checkPrefixExits(it)) {
                // Update longest word if this one is longer
                if (it.length() > longest.length()) {
                    longest = it;
                }
                // If same length, pick lexicographically smaller
                else if (it.length() == longest.length() && longest > it) {
                    longest = it;
                }
            }
        }

        // Step 3: Return result (handle empty case)
        return longest == "" ? " " : longest;
    }
};
