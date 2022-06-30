class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int>freq(26,0);
        unordered_map<int,bool>mp;
        int count=0;
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq[i]==0)continue;
            while(freq[i]>0 and mp.find(freq[i])!=mp.end()){
                freq[i]--;
                count++;
            }
            mp[freq[i]]=1;
        }
        return count;
    }
};
