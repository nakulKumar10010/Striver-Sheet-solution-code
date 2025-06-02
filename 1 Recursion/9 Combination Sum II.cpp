class Solution {
public:
    void solve(vector<int>& nums, int target, vector<vector<int>>& ans,
               vector<int>& ds, int i) {
        // if reached target
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int ind = i; ind < nums.size(); ind++) {
            // ind > i -> as for nxt recusrion call it will mismatch the ans u
            // can refer to vide 28:03
            if (ind > i && nums[ind] == nums[ind - 1])
                continue;
            if (nums[ind] > target)
                break;
            ds.push_back(nums[ind]);
            solve(nums, target - nums[ind], ans, ds, ind + 1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates, target, ans, ds, 0);
        return ans;
    }
};
