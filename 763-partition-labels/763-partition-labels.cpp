class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        vector<int>ans;
        int strt=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            mp[s[i]]=i;
        }
        int last_index = mp[s[0]];
        for(int i=0; i<n; i++){
            if(i<=last_index and mp[s[i]]<=last_index)continue;
            
            else if(i<=last_index and mp[s[i]]>last_index) last_index=mp[s[i]];
            
            else{
                ans.push_back(i-strt);
                strt=i;
                last_index = mp[s[i]];
            }
        }
        ans.push_back(n-strt);
        return ans;
    }
};