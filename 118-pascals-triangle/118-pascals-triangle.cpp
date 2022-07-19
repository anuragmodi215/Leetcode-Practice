class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>>dp;
        for(int i=0; i<rows; i++){
            dp.push_back(vector<int>(i+1,0));
        }
        for(int i=0; i<rows; i++){
            dp[i][0]=1;
            dp[i][dp[i].size()-1]=1;
        }
        
        
        for(int i=2; i<rows; i++){
            for(int j=1; j<dp[i].size()-1; j++){
                dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
            }
        }
        return dp;
    }
};