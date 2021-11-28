class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minInd=0,maxInd=0,mini=INT_MAX,maxi=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<mini){
                mini=nums[i];
                minInd=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                maxInd=i;
            }
        }
        int dis_end_mini=n-1-minInd;
        int dis_end_maxi=n-1-maxInd;
        
        int from_strt=max(minInd,maxInd)+1;
        int from_end=max(dis_end_mini,dis_end_maxi)+1;
        int both=min(minInd,dis_end_mini)+1+min(maxInd,dis_end_maxi)+1;
        return min(both,min(from_strt,from_end));
        
    }
};