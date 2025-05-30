void solve(int n,int i, vector<int>& arr,int& currSum, int k, int& count){
    //base case
    if(i >= n){
        if(k == currSum){
            count++;
        }
        
        return;
    }
    //take
    currSum =currSum + arr[i];
    solve(n, i+1, arr, currSum, k, count);
    //backtrack
    currSum = currSum-arr[i];
    
    //not take 
    solve(n, i+1, arr, currSum, k, count);
    
}

int findWays(vector<int>& arr, int k)
{
	int count= 0;
    int currSum = 0;
	solve(arr.size(), 0, arr, currSum, k, count);

	return count;
}
