class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &arr, int i, int n, vector<int>& nums){
        if(i >= n){
            ans.push_back(arr);
        }

        //take
        arr.push_back(nums[i]);
        solve(ans, arr, i+1, n, nums);
        //back tracking
        arr.pop_back();

        //not take
        solve(ans, arr, i+1, n, nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;

        solve(ans, arr, 0, nums.size(), nums);
        return ans;
    }
};
