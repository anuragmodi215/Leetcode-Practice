class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0,zerocnt=0;
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]==0) zerocnt++;
            while(zerocnt>k){
                if(nums[j]==0) zerocnt--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};