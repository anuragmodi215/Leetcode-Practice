class Solution {
public:
    int maxFreq(unordered_map<char,int>&mp){
        int freq=0;
        for(auto i:mp){
            freq = max(freq,i.second);
        }
        return freq;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int i=0,j=0;
        int n = s.size();
        int ans = 0;
        while(j<n){
            mp[s[j]]++;
            int mxf = maxFreq(mp);
            while(j-i+1-mxf>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                mxf = maxFreq(mp);
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};