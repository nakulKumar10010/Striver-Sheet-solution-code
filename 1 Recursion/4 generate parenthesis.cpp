class Solution {
public:
    void generate(vector<string> &valid,string& s, int open, int close) {
        if (open == 0 && close == 0) {
            valid.push_back(s);
            return;
        }

        if (open > 0) {
            s.push_back('(');
            generate(valid, s, open - 1, close);
            //backtrack
            s.pop_back();
        }

        if (close > 0) {
            if (open < close) {
                s.push_back(')');
                generate(valid, s, open, close - 1);
                //backtrack
                s.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        generate(ans, s, n, n);

        return ans;
    }
};
