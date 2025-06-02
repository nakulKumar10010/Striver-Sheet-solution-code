class Solution {
public:
    void solve(int k, int sum, int i, vector<vector<int>>& ans, vector<int>& ds){
        //if n and k is reached
        if(sum == 0 && ds.size() == k){
            ans.push_back(ds);
            return;
        }

        //taking choice for each and such that before inserting element the k is checked
        for(int j  = i; j < 10 && ds.size() < k; j++){
            ds.push_back(j);
            solve(k, sum-j, j+1, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(k, n, 1, ans, ds);
        return ans;
    }
};//JAI BABA KI
