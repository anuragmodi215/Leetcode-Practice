class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        if(n%2==1) return false;
        
        for(int i=0; i<n; i++){
            //if(st.empty() and s[i]==')' or s[i]=='}' or s[i]==']') return false;
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else
            {
                if(!st.empty()){
                if(st.top()=='(' and s[i]==')') st.pop();
                else if(st.top()=='{' and s[i]=='}')st.pop();
                else if(st.top()=='[' and s[i]==']')st.pop();
                else return false;
                }
                else return false;
            }
            
        }
    
        if(st.empty()) return true;
        return false;
    }
};