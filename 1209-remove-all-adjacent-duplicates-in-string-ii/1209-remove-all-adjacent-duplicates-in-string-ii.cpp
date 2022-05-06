class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>stack;
        int n = s.size();
        stack.push({s[0],1});
        for(int i=1; i<n; i++){
            if(!stack.empty() and stack.top().first==s[i]){
                stack.top().second++;
                if(stack.top().second==k){
                    stack.pop();
                }
            }
            else{
                stack.push({s[i],1});
            }
        }
        string ans="";
        
        while(!stack.empty()){
            //cout<<stack.top().first;
            int times = stack.top().second;
            for(int i=0; i<times; i++){
                ans += stack.top().first;
            }
            stack.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};