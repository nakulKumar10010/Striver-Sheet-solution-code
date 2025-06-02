class Solution {
public:
    bool isPalindrom(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++, end--;
        }
        return true;
    }
    void solve(string s, vector<vector<string>>& ans, vector<string>& str,
               int ind) {
        // partition is at last a|b|b|<-
        if (ind == s.size()) {
            ans.push_back(str);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (isPalindrom(s, ind, i)) {
                //range?
                str.push_back(s.substr(ind, i - ind + 1));
                solve(s, ans, str, i + 1);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;
        solve(s, ans, str, 0);
        return ans;
    }
};
