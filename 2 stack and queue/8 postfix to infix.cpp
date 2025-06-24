class Solution {
  public:
    string postToInfix(string exp) {
        // Stack to store intermediate infix expressions
        stack<string> st;

        // Traverse each character in the postfix expression
        for(int i = 0; i < exp.size(); i++){
            char ch = exp[i];

            // If the character is an operand (a-z, A-Z, or 0-9)
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
                // Convert the character to a string and push onto the stack
                // Reason: operands are single characters but we need to build strings for infix expressions
                st.push(string(1, ch));
            }
            // If the character is an operator
            else {
                // Pop the top two elements from the stack for the operator
                // Reason: In postfix, the operator comes after its operands, so we retrieve them in reverse order
                string op1 = st.top();  // First operand popped (actually second in original order)
                st.pop();
                string op2 = st.top();  // Second operand popped (actually first in original order)
                st.pop();

                // Combine them into an infix expression with parentheses
                // Reason: We add parentheses to preserve the intended order of operations
                st.push('(' + op2 + ch + op1 + ')');
            }
        }

        // The final element on the stack is the full infix expression
        return st.top();
    }
};
