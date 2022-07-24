class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(m>n){
            return "";
        }
        string ans(n+1,'*');
        unordered_map<char,int>mp;
        int i=0,j=0;
        for(auto i:t){
            mp[i]++;
        }
        int cnt=mp.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    cnt--;
                }
            }
            while(i<=j and cnt==0){
                    //cout<<j<<" ";
                    if(ans.size()>j-i+1){
                        ans = s.substr(i,j-i+1);
                        //cout<<ans;
                    }
                    if(mp.find(s[i])!=mp.end()){
                        if(mp[s[i]]==0)cnt++;
                        mp[s[i]]++;
                        
                    }
                    i++;
                }
            j++;
        }
    // cout<<ans;
    //    if(ans==s and s!=t) return "";
        if(ans[0]=='*') return "";
        return ans;
    }
};