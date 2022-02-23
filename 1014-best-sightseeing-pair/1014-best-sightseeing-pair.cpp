class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=INT_MIN;
        int strtGain=values[0];
        for(int i=1; i<n; i++){
            strtGain=max(strtGain,values[i-1]+i-1);
            ans = max(ans,strtGain+values[i]-i);
        }
        return ans;
    }
};