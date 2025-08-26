class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();           // Number of existing intervals
        vector<vector<int>> ans;            // Result vector to store final intervals
        int i = 0;                          // Index to iterate through intervals

        // 1. Add all intervals that come before the newInterval (no overlap)
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);    // Current interval ends before newInterval starts
            i++;
        }    

        // 2. Merge all overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            // Update the start of newInterval to the smallest start
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            // Update the end of newInterval to the largest end
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Add the merged newInterval
        ans.push_back(newInterval);

        // 3. Add all remaining intervals that come after newInterval (no overlap)
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;  // Return the merged intervals
    }
};
