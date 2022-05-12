class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len =0;
        int maxLen=0;
        int i=0,j=0;
        int n = nums.size();
        while(i<n and j<n){
            if(nums[i]==1){
                j=i;
                while(j<n and nums[j]==1){
                    j++;
                }
                len = j-i;
                maxLen = max(maxLen,len);
                i=j;
            }
            else{
                i++;
            }
        }
        return maxLen;
    }
};