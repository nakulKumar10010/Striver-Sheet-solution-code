class Solution {
  public:
    void solve(vector<int>& arr, vector<int>& ans, int currSum, int i){
        if(i == arr.size()){
            ans.push_back(currSum);
            return;
        }
        
        //take
        solve(arr, ans, currSum + arr[i], i+1);
        
        //not take
        solve(arr, ans, currSum, i+1);
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        solve(arr, ans, 0, 0);
        return ans;
    }
};
