class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>mp;
        int n = nums.size();
        int m = nums[0].size();
        for(int i=0; i<m; i++){
            mp[nums[0][i]]=0;
        }
       
        for(int i=1; i<n; i++){
            m=nums[i].size();
            for(int j=0; j<m; j++){
                if(mp.find(nums[i][j])!=mp.end()){
                    if(mp[nums[i][j]]==i-1){
                        mp[nums[i][j]]=i;
                    }
                    else{
                        mp.erase(nums[i][j]);
                    }
                }
            }
        }
        vector<int>v;
        for(auto i:mp){
            if(i.second==n-1)
               v.push_back(i.first);
        }
        return v;
    }
};