// User function Template for C++

class Solution {
  public:
    // DFS function to explore the island and store its shape
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, 
             vector<pair<int, int>> &vec, int rowBase, int colBase){
        
        vis[row][col] = 1; // Mark current cell as visited
        
        // Store the relative position to the starting cell of the island
        vec.push_back({row - rowBase, col - colBase});
        
        int n = grid.size();      // Number of rows
        int m = grid[0].size();   // Number of columns
        
        // Directions: up, left, down, right
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        
        // Explore all 4 directions
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            // Check for valid unvisited land cell (value 1)
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    // Recursive DFS call
                    dfs(nrow, ncol, vis, grid, vec, rowBase, colBase);
                }
        }
        
    }

    // Main function to count distinct islands
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();      // Number of rows
        int m = grid[0].size();   // Number of columns
        
        // Visited matrix to track visited cells
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Set to store unique island shapes
        set<vector< pair<int, int> >> st;
        
        // Traverse the entire grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // If cell is unvisited and part of an island (value 1)
                if(!vis[i][j] && grid[i][j] == 1){
                    vector< pair<int, int> > temp; // To store shape of current island
                    dfs(i, j, vis, grid, temp, i, j); // Start DFS from current cell
                    st.insert(temp); // Insert the shape into the set
                }
            }
        }
        
        // The number of unique island shapes is the answer
        return st.size();
    }
};
