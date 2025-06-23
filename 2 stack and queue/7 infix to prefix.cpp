//right association not accounted for that use thus will loop in line 41
//while (!st.empty() && (prec(st.top()) > prec(s[i]) || (prec(st.top()) == prec(s[i]) && s[i] != '^')))
class Solution {
  public:

    // Function to return precedence of operators
    int prec(char c) {
        if (c == '^')         // Highest precedence for exponentiation
            return 3;
        else if (c == '*' || c == '/') // Higher precedence than + or -
            return 2;
        else if (c == '+' || c == '-') // Lowest among operators
            return 1;
        else
            return -1;        // Non-operator characters
    }

    // Function to convert infix expression to postfix
    string infixToPostfix(string& s) {
        stack<char> st;   // Stack to hold operators and parentheses
        string res;       // Final postfix result

        // Iterate through each character in the infix expression
        for (int i = 0; i < s.length(); i++) {

            // If the character is an operand (letter or digit), add to result
            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9')) {
                res += s[i];
            }

            // If the character is an opening parenthesis, push to stack
            else if (s[i] == '(') {
                st.push(s[i]);
            }

            // If the character is a closing parenthesis
            else if (s[i] == ')') {
                // Pop and add to result until matching '(' is found
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                // Pop the '(' from stack (but do not add to result)
                if (!st.empty()) {
                    st.pop();
                }
            }

            // If the character is an operator (+, -, *, /, ^)
            else {
                // While top of stack has equal or higher precedence (left-associative case),
                // pop from stack and add to result
                while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                    res += st.top();
                    st.pop();
                }
                // Push current operator to stack
                st.push(s[i]);
            }
        }

        // Pop and append any remaining operators from the stack
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res; // Return the final postfix expression
    }
};
