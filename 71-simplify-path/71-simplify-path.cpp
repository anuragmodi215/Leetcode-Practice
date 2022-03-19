class Solution {
public:
    string simplifyPath(string s) {
        int n=s.size();
        stack<string>st;
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]=='/')continue;
            else{
                string temp="";
                while(i<n and s[i]!='/'){
                    temp+=s[i++];
                }
                i--;
                if(temp==".."){
                    if(!st.empty()) st.pop();
                }
                else if(temp==".") continue;
                else st.push(temp);
            }
        }
        if(st.empty()) ans="/";
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};