class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            else{
                for(int j=i+1; j<n; j++){
                    if(j>i+1 and nums[j]==nums[j-1])continue;
                    else{
                        int k = j+1;
                        int l = n-1;
                        int a = nums[i];
                        int b = nums[j];
                        int newTarget = target-a-b;
                        while(k<l){
                            int c = nums[k];
                            int d = nums[l];
                            int sum = c+d;
                            if(sum==newTarget){
                                ans.push_back({a,b,c,d});
                                while(k<l and nums[k]==nums[k+1]){
                                    k++;
                                }
                                k++;
                                while(k<l and nums[l]==nums[l-1]){
                                    l--;
                                }
                                l--;
                            }
                            else if(sum<newTarget){
                                k++;
                            }
                            else if(sum>newTarget){
                                l--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};