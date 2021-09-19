class Solution {
public:
    bool isValid(string s) {
     stack<char> st;
        if(s.size()%2==1) return false;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' or s[i] =='{' or s[i]=='['){
                st.push(s[i]);
            }
                else{
                    if(!st.empty()){
                    if(s[i]=='}' and st.top()=='{'){
                        st.pop();
                    }
                    else if(s[i]==')' and st.top()=='('){
                        st.pop();
                    }
                    else if(s[i]==']' and st.top()=='['){
                        st.pop();
                    }
                        else return false;
                    }
                    else return false;
                }
        }
        if(st.empty()) return true;
        else return false;
    }
};