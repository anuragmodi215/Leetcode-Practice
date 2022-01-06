class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int>mp;
        int prefixSum=0,ans=0;
        mp[prefixSum]=-1;
        
        for(int i=0; i<n; i++){
            if(nums[i]==1) prefixSum+=1;
            else prefixSum-=1;
            
            if(mp.find(prefixSum)!=mp.end()){
                ans=max(ans,i-mp[prefixSum]);
            }
            else mp[prefixSum]=i;
        }
        return ans;
    }
};





