class Solution {
public:
    vector<string>v;
    void solve(string input, string output){
        if(input.size()==0){
            v.push_back(output);
            return;
        }
        string op1,op2;
        op1=output;
        op2=output;
        if(isalpha(input[0])){
            op1.push_back(toupper(input[0]));
            op2.push_back(tolower(input[0]));
            
            input.erase(input.begin()+0);
            solve(input, op1);
            solve(input, op2);
        }
        else{
            output.push_back(input[0]);
            input.erase(input.begin()+0);
            solve(input,output);
        }

        
    }
    vector<string> letterCasePermutation(string s) {
        string input=s;
        string output="";
        solve(input,output);
        return v;
    }
};