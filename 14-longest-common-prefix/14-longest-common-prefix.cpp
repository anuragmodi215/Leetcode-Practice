class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        string ans = str[0];
        for(int i=1; i<n; i++){
            int j;
            int len = min(ans.size(), str[i].size());
            for(j=0; j<len; j++){
                if(ans[j]!=str[i][j])break;
            }
            ans = str[i].substr(0,j);
            if(ans=="") break;
        }
        return ans;
    }
};