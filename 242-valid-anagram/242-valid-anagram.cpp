class Solution {
public:
    bool isAnagram(string s, string t) {
        int dp[26]={0};
        int biggiLength = s.size();
        int simmiLength = t.size();
        if(biggiLength<simmiLength) return false;
        
        for(int i=0; i<biggiLength; i++){
            dp[s[i]-'a']++;
        }
        for(int i=0; i<simmiLength; i++){
            dp[t[i]-'a']--;
            if(dp[t[i]-'a']<0){
                return false;
            }
        }
        for(int i=0; i<26; i++){
            if(dp[i]!=0) return false; 
        }
        return true;
    }
};