class Solution {
public:
    unordered_map<string,int>mp;
    vector<string>v;
    int countMinInvalid(string s){
        stack<char>st;
        //int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') st.push(s[i]);
            // else if(st.size()>0 and s[i]==')' and st.top()=='(') st.pop();
            // else if(s[i]==')')st.push(s[i]);
            else if(s[i]==')'){
                if(st.size()>0 and st.top()=='(') st.pop();
                else st.push(')');
            }
        }
        cout<<st.size();
        return st.size();
    }
    
     void remove(string s,int n){
         //if(set.find(s)!=set.end()) return;
         if(mp[s]!=0) return;
         else mp[s]++;
         if(n<0) return;
         if(n==0){
             if(!countMinInvalid(s)){
                v.push_back(s);
             }
             return;
         }
         
         for(int i=0; i<s.size(); i++){
             string left=s.substr(0,i);
             string right=s.substr(i+1);
             remove(left+right,n-1);
         }
         return;
     }
    vector<string> removeInvalidParentheses(string s) {
        int n = countMinInvalid(s);
        remove(s,n);
        
        // for(auto i: set){
        //     v.push_back(i);
        // }
        return v;
    }
};