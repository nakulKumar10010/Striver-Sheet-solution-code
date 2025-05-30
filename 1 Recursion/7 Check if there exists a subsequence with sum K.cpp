void solve(int n,int i, vector<int>& arr,int& currSum, int k, bool& flag){
    //base case
    if(flag) return;
    if(i >= n){
        if(k == currSum){
            flag = true;
        }
        
        return;
    }
    //take
    currSum =currSum + arr[i];
    solve(n, i+1, arr, currSum, k, flag);
    //backtrack
    currSum = currSum-arr[i];
    
    //not take 
    solve(n, i+1, arr, currSum, k, flag);
    
}

int findWays(vector<int>& arr, int k)
{
	bool flag = false;
    int currSum = 0;
	solve(arr.size(), 0, arr, currSum, k, flag);

	return flag;
}
