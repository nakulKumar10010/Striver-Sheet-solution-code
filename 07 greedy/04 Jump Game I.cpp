class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInd = 0;  // Tracks the farthest index we can reach
        
        // Loop through each index
        for (int currInd = 0; currInd < nums.size(); currInd++) {
            
            // If current index is beyond the farthest reachable index, we are stuck
            if (currInd > maxInd)
                return false;
            
            // Update farthest reachable index
            maxInd = max(maxInd, currInd + nums[currInd]);
        }

        // If we finish the loop, it means we can reach (or surpass) the last index
        return true;
    }
};
