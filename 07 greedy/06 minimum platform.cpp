/*✅ Key points in logic:

Sort arrival and departure times independently.

Use two pointers (one for arrival, one for departure) and a counter to simulate the station usage.

For every arrival before a departure → increment count.

For every departure before the next arrival → decrement count.

Track the maximum count at any time → that’s the answer.*/

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // n stores the number of trains
        int n = arr.size();
        
        // Sort the arrival and departure times separately
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        // cnt -> current number of platforms occupied
        // maxCnt -> maximum platforms needed at any time
        int cnt = 0;
        int maxCnt = 0; 
        
        // ati -> pointer for arrival times
        // dti -> pointer for departure times
        int ati = 0;
        int dti = 0;
        
        // Loop until we have checked all arrivals
        while(ati < n){
            // If next train arrives before the earliest departure,
            // we need an extra platform
            if(arr[ati] <= dep[dti]){
                cnt++;         // One more train has arrived
                ati++;         // Move to next arrival
            }
            else{
                // If next departure is before the next arrival,
                // one platform gets free
                cnt--;         // One train has departed
                dti++;         // Move to next departure
            }
            
            // Update max platforms needed so far
            maxCnt = max(maxCnt, cnt);
        }
        
        // Return the maximum platforms required at any time
        return maxCnt;
    }
};
