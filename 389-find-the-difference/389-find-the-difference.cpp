class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto i:t){
            mp[i]++;
        }
        int n=s.size();
        for(int i=0; i<n; i++){
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(s[i]);
        }
        char x;
        for(auto i:mp){
            x=i.first;
        }
        return x;
    }
};