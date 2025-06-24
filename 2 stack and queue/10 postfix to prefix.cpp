class Solution {
  public:
    // Function to convert postfix expression to prefix expression
    string postToPre(string post_exp) {
        // Stack to store intermediate expressions
        stack<string> st;

        // Traverse the postfix expression from left to right
        for(int i = 0; i < post_exp.size(); i++){
            char ch = post_exp[i];

            // If character is an operand (letter or digit)
            if((ch >= 'a' && ch <= 'z') || 
               (ch >= 'A' && ch <= 'Z') || 
               (ch >= '0' && ch <= '9')){
                // Convert character to string and push onto the stack
                st.push(string(1, ch));
            }
            // If character is an operator
            else{
                // Pop top two elements from the stack
                string op1 = st.top(); // first operand (right side)
                st.pop();
                string op2 = st.top(); // second operand (left side)
                st.pop();

                // Form prefix expression: operator + operand2 + operand1
                st.push(ch + op2 + op1);
            }
        }

        // The final result will be the only element left in the stack
        return st.top();
    }
};
