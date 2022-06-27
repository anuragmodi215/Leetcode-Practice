class Solution {
public:
    int minPartitions(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(s[i]-'0',ans);
        }
        return ans;
    }
};