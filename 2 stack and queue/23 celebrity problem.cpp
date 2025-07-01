class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int top = 0;
        int down = mat.size() - 1;
        
        // Use two pointers to find potential celebrity
        while(top < down){
            // If top knows down → top can't be celebrity, move top forward
            if(mat[top][down] == 1) top++;
            
            // Else if down knows top → down can't be celebrity, move down backward
            else if(mat[down][top] == 1) down--;
            
            // If neither knows each other → move both (this part is logically problematic, but as per request, code is not modified)
            else top++, down--;
        }
        
        // After loop, top == down means potential celebrity found at 'top'
        if(top == down){
            for(int i = 0; i < mat.size(); i++){
                if(i == top) continue; // skip self-check
                
                // Check if everyone knows 'top' and 'top' knows no one
                if(mat[i][top] != 1 || mat[top][i] != 0) return -1;
            }
            // 'top' is celebrity
            return top;
        }
        
        // No celebrity found if top > down
        return -1;
    }
};
