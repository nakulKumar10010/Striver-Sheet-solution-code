/* 
    Problem: Count distinct substrings in a string.
    Approach: Use a Trie to store all substrings.
              - Each new node created in the Trie means we found a new unique substring.
              - Finally, return count of created nodes (+1 for empty substring).
*/

// Node class for Trie
class Node {
public:
    Node* links[26];  // 26 lowercase English letters

    // Check if node already has a link for this character
    bool containsKey(char ch) {
        return links[ch - 'a'];
    }

    // Create a new link for this character
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Get the node corresponding to this character
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

int countDistinctSubstring(string s) {
    int cnt = 0;                // counter for distinct substrings
    Node* root = new Node();    // root of the Trie

    // Try to insert all substrings of 's'
    for (int i = 0; i < s.size(); i++) {
        Node* node = root;  // start from root for each substring
        for (int j = i; j < s.size(); j++) {
            // If current character path does not exist → new substring found
            if (!node->containsKey(s[j])) {
                cnt++;  // increase distinct substring count
                node->put(s[j], new Node()); // create new path
            }
            // Move to the next node in Trie
            node = node->get(s[j]);
        }
    }

    // +1 to include the empty substring
    return cnt + 1;
}
