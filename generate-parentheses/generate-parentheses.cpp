class Solution {
public:
    void solve(int open, int close, vector<string>&v, string output){
        if(open==0 and close ==0){
            v.push_back(output);
            return;
        }
        if(open!=0){
            string op1=output;
            op1.push_back('(');
            solve(open-1,close,v,op1);
        }
        if(close>open){
            string op2=output;
            op2.push_back(')');
            solve(open,close-1,v,op2);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        vector<string>v;
        string output="";
        solve(open,close,v,output);
        return v;
    }
};