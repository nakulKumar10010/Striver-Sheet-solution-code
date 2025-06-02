class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& arr, vector<int>& ds,
               int i) {
        // push each pair
        ans.push_back(ds);

        // find choice for each index and neglecting the duplicate one
        for (int j = i; j < arr.size(); j++) {
            if (j > i && arr[j] == arr[j - 1])
                continue;
            ds.push_back(arr[j]);
            solve(ans, arr, ds, j + 1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;

        solve(ans, nums, ds, 0);
        return ans;
    }
};
