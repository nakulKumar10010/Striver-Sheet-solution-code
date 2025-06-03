class Solution {
  public:
    void solve(vector<vector<int>>& maze, vector<string>& ans, string& path, int i, int j, int n){
        //base case : reached destination
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        //out of boundary or blocked cell or visited
        if(i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0) return;
        
        maze[i][j] = 0;//mark visited
        //up
        path.push_back('U');
        solve(maze, ans, path, i-1, j, n);
        path.pop_back();
        //down
        path.push_back('D');
        solve(maze, ans, path, i+1, j, n);
        path.pop_back();
        //left
        path.push_back('L');
        solve(maze, ans, path, i, j-1, n);
        path.pop_back();
        //right
        path.push_back('R');
        solve(maze, ans, path, i, j+1, n);
        path.pop_back();
        
        maze[i][j] = 1;//backtracking
        
        return;//no possible 
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        string path;
        int n = maze.size();
         // check if start or end cell is blocked
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0)
            return ans;
        solve(maze, ans, path, 0, 0, n);
        //ATQ: Return the final result vector in lexicographically smallest 
        sort(ans.begin(), ans.end());
        return ans;
    }
};//JAI BABA KI
