class Solution {
  public:
    vector<int> minPartition(int N) {
        // Available currency denominations in descending order
        int currency[] = { 2000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
        int i = 0;  // index to track current denomination
        vector<int> ans; // to store the result (list of notes/coins used)
        
        // Loop until the amount N becomes 0
        while(N > 0){
            // If current denomination is less than or equal to N
            if(currency[i] <= N){
                ans.push_back(currency[i]); // choose this denomination
                N -= currency[i]; // subtract its value from N
            }
            else{
                i++; // move to the next smaller denomination
            }
        }
        
        // Return the list of chosen denominations
        return ans;
    }
};
