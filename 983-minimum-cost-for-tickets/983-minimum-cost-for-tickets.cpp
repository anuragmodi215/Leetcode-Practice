class Solution {
public:
    int helper(vector<int>& days, vector<int>& costs, int i, int n,vector<int>&dp){
        if(i==n) return 0;
        
       
        if(dp[i]!=-1) return dp[i];
        int x=costs[0]+helper(days,costs,i+1,n,dp);
        
        int i_skip;
        for(i_skip=i; i_skip<n and days[i_skip]<days[i]+7; i_skip++);
        int y=costs[1]+helper(days,costs,i_skip,n,dp);
        
        for(i_skip=i; i_skip<n and days[i_skip]<days[i]+30; i_skip++);
        int z=costs[2]+helper(days,costs,i_skip,n,dp);
        
        return dp[i]=min(x,min(y,z));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,-1);
        return helper(days,costs,0,n,dp);
    }
};