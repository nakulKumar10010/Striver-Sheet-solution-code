// User function Template for C++

class Solution {
  public:
    // Function to convert prefix expression to postfix expression
    string preToPost(string pre_exp) {
        stack<string> st;

        // Traverse the prefix expression from right to left
        for(int i = pre_exp.size()-1; i >= 0; i--){
            char ch = pre_exp[i];

            // If character is an operand (letter or digit)
            if((ch >= 'a' && ch <= 'z') || 
               (ch >= 'A' && ch <= 'Z') || 
               (ch >= '0' && ch <= '9')){
                // Convert character to string and push onto the stack
                st.push(string(1, ch));
            }
            // If character is an operator
            else{
                // Pop top two operands from the stack
                string op1 = st.top(); // first operand
                st.pop();
                string op2 = st.top(); // second operand
                st.pop();

                // Form postfix expression: operand1 + operand2 + operator
                st.push(op1 + op2 + ch);
            }
        }

        // The final result is the complete postfix expression
        return st.top();
    }
};
