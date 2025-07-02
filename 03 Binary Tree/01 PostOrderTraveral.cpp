// method - 1 : using two stack or just reverse the ans
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        // root
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);

        // right as stack 
        if (temp->right != NULL) {
            st.push(temp->right);
        }
        // left as stack
        if (temp->left != NULL) {
            st.push(temp->left);
        }
    }

    return ans;
}

//mehtod 2 : using 1 stack or no reversal
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL)
        return ans; // If tree is empty, return empty result

    stack<TreeNode*> st;
    TreeNode* curr = root;

    // Loop runs while there are nodes to process either in stack or as current node
    while (!st.empty() || curr != NULL) {
        if (curr != NULL) {
            // Go as left as possible, push all nodes along the path
            st.push(curr);
            curr = curr->left;
        } else {
            // Look at the right subtree of the top node
            TreeNode* temp = st.top()->right;

            if (temp == NULL) {
                // If no right child exists, process the node (postorder: left-right-root)
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);

                // Check if just processed node was the right child of the next node on stack
                // If so, keep processing upwards as their right subtrees are done
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            } else {
                // If right child exists, move to it
                curr = temp;
            }
        }
    }

    return ans;
}
