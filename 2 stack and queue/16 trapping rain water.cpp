//method 1
class Solution {
public:
    // Function to compute prefix maximums (max to the left of each position including itself)
    vector<int> prefixMax(vector<int>& arr, int n) {
        vector<int> ans(n);
        int maxi = arr[0];
        for (int i = 0; i < n; i++) {
            // Update the running maximum seen so far from the left
            maxi = max(maxi, arr[i]);
            ans[i] = maxi;
        }
        return ans;
    }

    // Function to compute suffix maximums (max to the right of each position including itself)
    vector<int> surffixMax(vector<int>& arr, int n) {
        vector<int> ans(n);
        int maxi = arr[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            // Update the running maximum seen so far from the right
            maxi = max(maxi, arr[i]);
            ans[i] = maxi;
        }
        return ans;
    }

    // Main function to compute trapped rain water
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Compute left and right max arrays
        vector<int> leftMax(n), rightMax(n);
        leftMax = prefixMax(height, n);
        rightMax = surffixMax(height, n);
        
        int total = 0;
        // Calculate trapped water at each position
        for (int i = 0; i < n; i++) {
            // Water can only be trapped if current height is less than both left and right max
            if (height[i] < leftMax[i] && height[i] < rightMax[i]) {
                total += min(leftMax[i], rightMax[i]) - height[i];
            }
        }
        return total; // Return the total amount of trapped water
    }
};


//method 2
class Solution {
public:
    int trap(vector<int>& height) {
        int lmax, rmax, total, l, r, n;
        lmax = rmax = total = l = 0;      // Initialize left max, right max, total water, and left pointer
        r = height.size() - 1;            // Initialize right pointer to the last index

        // Two-pointer approach: move pointers towards each other
        while (l < r) {
            // Always process the smaller height side first
            if (height[l] <= height[r]) {
                // If lmax is greater, water can be trapped
                if (lmax > height[l])
                    total += lmax - height[l];  // Add trapped water at l
                else
                    lmax = height[l];           // Update lmax if current is bigger
                l++;                             // Move left pointer to the right
            } else {
                // If rmax is greater, water can be trapped
                if (rmax > height[r])
                    total += rmax - height[r];  // Add trapped water at r
                else
                    rmax = height[r];           // Update rmax if current is bigger
                r--;                             // Move right pointer to the left
            }
        }

        return total;  // Final trapped water amount
    }
};
