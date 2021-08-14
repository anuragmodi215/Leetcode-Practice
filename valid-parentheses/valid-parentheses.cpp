class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        if(n%2==1) return 0;
        
        for(int i=0; i<n; i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    char t = st.top();
                    st.pop();
                    if(s[i]==')' and t=='('){
                        continue;
                    }
                    else if(s[i]=='}' and t=='{'){
                        continue;
                    }
                    else if(s[i]==']' and t=='['){
                            continue;
                        }
                    else return 0;
                    }
                 else return false;
                }
            }
        if(st.empty())
        return 1;
        else
        return 0;
        }
    };
