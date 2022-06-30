class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int maxi=0;
        int windowSum=0;
        
        int i=0,j=0;
        while(j<n){
            if(colors[i]==colors[j]){
                windowSum+=neededTime[j];
                maxi = max(maxi,neededTime[j]);
                j++;
            }
            else{
                //cout<<windowSum-maxi<<endl;
                ans = ans + windowSum-maxi;
                i=j;
                windowSum=0;
                maxi=0;
            }
        }
        ans = ans+windowSum-maxi;
        return ans;
    }
};