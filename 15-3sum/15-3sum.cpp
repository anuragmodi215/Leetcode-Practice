class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            else{
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[k];
                    int sum = a+b+c;
                    if(sum==0){
                        ans.push_back({a,b,c});
                        while(j<k and nums[j]==nums[j+1]) j++;
                        while(j<k and nums[k]==nums[k-1]) k--;
                        j++;k--;
                    }
                    else if(sum<0){
                        j++;
                    }
                    else if(sum>0){
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};