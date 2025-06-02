class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans,
               vector<int>& ds, int i) {
        // base case 1 - if reached target
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        // full iteration
        if (i == candidates.size())
            return;
        // take
        if (target > 0) {
            ds.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ans, ds, i);
            ds.pop_back();
        }
        // not take
        solve(candidates, target, ans, ds, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates, target, ans, ds, 0);
        return ans;
    }
};
