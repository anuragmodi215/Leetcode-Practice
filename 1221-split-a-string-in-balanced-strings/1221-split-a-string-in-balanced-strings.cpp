class Solution {
public:
    int balancedStringSplit(string s) {
        int balanced=0;
        int n=s.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='L') balanced++;
            else balanced--;
            if(balanced==0) cnt++;
        }
        return cnt;
    }
};