1 Recursion 
class Solution {
  public:
    int solve(int i, int n, vector<int>& height){
        if(i == n)
            return 0;
        if(i > n)
            return INT_MAX;

        int one = solve(i + 1, n, height) + abs(height[i] - height[i + 1]);
        int two = INT_MAX;
        if(i + 2 <= n)
            two = solve(i + 2, n, height) + abs(height[i] - height[i + 2]);

        return min(one, two);
    }

    int minCost(vector<int>& height) {
        return solve(0, height.size() - 1, height);
    }
};
