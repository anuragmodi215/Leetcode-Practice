class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        if(n<1) return 0;
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int length=1,maxi=1;
        
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]-1)!=mp.end()){
                continue;
            }
            else{
               int number = nums[i];
                while(mp.find(number+1)!=mp.end()){
                    length++;
                    number++;
                }
                maxi = max(length,maxi);
                length=1;
            }
        }
        return maxi;
    }
};