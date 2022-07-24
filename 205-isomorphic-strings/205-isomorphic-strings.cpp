class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char>mp;
        unordered_map<char,char>mt;
        for(int i=0; i<n; i++){
            if(mp[s[i]]==0 and mt[t[i]]==0){
                mp[s[i]]=t[i];
                mt[t[i]]=s[i];
            }
            else if(mp[s[i]]!=t[i]) return false;
        }
        return true;
    }
};