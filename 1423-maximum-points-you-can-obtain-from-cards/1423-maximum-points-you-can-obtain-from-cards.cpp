class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(auto i:cardPoints) sum+=i;
        if(n==k) return sum;
        int i=0,j=0;
        int mini=INT_MAX;
        int windowSum=0;
        k=n-k;
        while(j<n){
            if(j-i+1<k){
                windowSum+=cardPoints[j];
                j++;
            }
            else{
                windowSum+=cardPoints[j];
                mini = min(mini,windowSum);
                windowSum-=cardPoints[i];
                i++;j++;
            }
        }
        return sum-mini;
    }
};