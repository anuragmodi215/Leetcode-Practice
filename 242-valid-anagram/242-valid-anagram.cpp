class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n1!=n2) return false;
        unordered_map<char,int>mp;
        for(int i=0; i<n1; i++){
            mp[s[i]]++;
        }
        for(int i=0; i<n2; i++){
            mp[t[i]]--;
            if(mp[t[i]]<0) return false;
        }
        // if(mp.size()==0) return true;
        // else return false;
        return true;
        
    }
};