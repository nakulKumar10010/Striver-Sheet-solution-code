class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;

        // Traverse the prefix expression from right to left
        // (Change 1 compared to postfix which is L to R)
        for(int i = pre_exp.size()-1; i >= 0; i--){
            char ch = pre_exp[i];

            // If the character is an operand (letter or digit)
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')|| (ch >= '0' && ch <= '9')){
                // Convert the character to a string and push onto the stack
                st.push(string(1, ch));
            }
            // If the character is an operator
            else{
                // Pop the first operand from the stack
                string op1 = st.top();
                st.pop();
                // Pop the second operand from the stack
                string op2 = st.top();
                st.pop();
                // Combine them into a valid infix expression
                // Change 2: In prefix, format is (op1 operator op2)
                st.push('(' + op1 + ch + op2 + ')');
            }
        }

        // The final element of the stack is the complete infix expression
        return st.top();
    }
};
