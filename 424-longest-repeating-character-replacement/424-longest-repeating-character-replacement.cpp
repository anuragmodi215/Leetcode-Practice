class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26);
        int n = s.size();
        int i=0,j=0;
        int maxCount=0;
        int ans = 0;
        for(; j<n; j++){
            count[s[j]-'A']++;
            maxCount = max(maxCount, count[s[j]-'A']);
            while(j-i+1-maxCount>k){
                count[s[i]-'A']--;
                i++;
                maxCount=0;
                for(int i=0; i<26; i++){
                    maxCount = max(count[i],maxCount);
                }
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};