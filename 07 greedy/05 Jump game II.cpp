class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;       // Counts the minimum number of jumps
        int l = 0;           // Left boundary of the current level (current jump range)
        int r = 0;           // Right boundary of the current level (max index we can reach in this jump)

        // Continue until we've reached (or passed) the last index
        while (r < nums.size() - 1) {
            int farthest = 0; // Tracks the farthest index reachable in the next jump

            // Explore all positions within the current level [l, r]
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]); 
                // i + nums[i] is the farthest we can go from position i
            }

            // Move to the next level
            l = r + 1;       // Next level starts after current right boundary
            r = farthest;    // Update right boundary to farthest we can reach in next jump
            jumps++;         // We've completed one jump
        }

        return jumps; // Minimum number of jumps needed
    }
};
