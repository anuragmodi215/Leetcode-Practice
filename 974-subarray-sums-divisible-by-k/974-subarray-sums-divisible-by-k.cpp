class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mp(k+1,0);
        int ps=0;
        mp[ps]=1;
        int cnt=0;
        for(int i=0; i<n; i++){
            ps +=nums[i];
            ps = ((ps%k)+k)%k;
            if(mp[ps]!=0){
                cnt+=mp[ps];
            }
            mp[ps]++;
        }
        return cnt;
    }
};