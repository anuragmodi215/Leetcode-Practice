class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        int n = v.size();
        string ans = v[0];
        for(int i=1; i<n; i++){
            int j;
            for(j=0; j<v[i].size(); j++){
                if(ans[j]!=v[i][j]){
                    cout<<45;
                    break;
                }
            }
            cout<<j;
            ans = ans.substr(0,j);
            if(ans ==""){
                return ans;
            }
        }
        return ans;
    }
};