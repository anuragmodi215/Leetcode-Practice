class Solution {
public:
    vector<string>ans;
    void solve(string inp, string out){
        if(inp.size()==0){
            ans.push_back(out);
            return;
        }
        
        else if(isalpha(inp[0])){
            string output1 = out;
            string output2=out;
            
             output1.push_back(tolower(inp[0]));
             output2.push_back(toupper(inp[0]));
            inp = inp.substr(1);
            solve(inp, output1);
            solve(inp, output2);
        }
        else{
            string output1 = out;
            output1.push_back(inp[0]);
            inp = inp.substr(1);
            solve(inp, output1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(s,"");
        return ans;
    }
};