class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,cnt=0;
        int n=nums.size();
            for(i=0; i<n; i++){
                cout<<i<<" ";
                if(nums[i]==1){
                    j=i;
                    while(nums[j]==1 and j<n){
                        cnt=max(cnt,j-i+1);
                        j++;
                        //cout<<j<<" ";
                        if(j>=n) break;
                    }
                    i=j;
                    //if(j>=n) break;
                }
            }
        return cnt;
    }
};