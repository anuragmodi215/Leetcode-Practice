class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        unordered_map<char,int>freq;
        string ans="";
        vector<int>visited(26,0);
        stack<char>st;
        for(int i=0; i<n ;i++){
            freq[s[i]]++;
        }
        for(int i=0; i<n; i++){
            freq[s[i]]--;
            if(!visited[s[i]-'a']){
                while(!st.empty() and st.top()>s[i] and freq[st.top()]>0){
                    visited[st.top()-'a']=0;
                    st.pop();
                }
                st.push(s[i]);
                visited[s[i]-'a']=1;
            }
            
        }
        
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};