class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>visited(26);
        unordered_map<char,int>freq;
        stack<char>st;
        string ans="";
        for(int i=0; i<n; i++){
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