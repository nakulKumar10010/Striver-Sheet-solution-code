class Solution {
public:
    void solve(string output, string input, vector<string>& ans, int index, string mapping[]){
        //base case
        if(index>=input.length()){
            ans.push_back(output);
            return;
        }
        //digit to letter
        int number = input[index]-'0';
        string value = mapping[number];
        // iterate over each letter for possible combination
        for(int i=0;i<value.length(); i++){
            output.push_back(value[i]);
            solve(output,input,ans,index+1,mapping);
            output.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string mapping[10]={"","" ,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output = "";
        int index=0;
        solve(output, digits, ans, index, mapping);
        return ans;

    }
};
