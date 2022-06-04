class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(auto i: s){
            if(i=='{' or i=='(' or i=='['){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    if(i==')' and st.top()=='(') st.pop();
                    else if(i=='}' and st.top()=='{') st.pop();
                    else if(i==']' and st.top()=='[') st.pop();
                    else{
                        return false;
                    }
                }
                else return false;
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};