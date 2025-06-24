#include <stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(n);

    for(int i=n-1; i>=0 ; i--){
        int curr = arr[i];
        
        while(!s.empty() && curr <= s.top()){
            s.pop();
        }
        if(s.empty())
            ans[i] = -1;
        else 
            ans[i] = s.top();
        s.push(curr);
        
    }

    return ans;
}
