class Solution {
public:
    int a,b,c,d;
    bool helper(vector<int>& nums, int ind){
        if(ind == nums.size()){
            if(a==0 and b==0 and c==0 and d==0) return true;
            else return false;
        }
        
        if(nums[ind]<=a){
            a = a-nums[ind];
            if(helper(nums,ind+1)) return true;
            a = a+nums[ind];
        }
        if(nums[ind]<=b){
            b = b-nums[ind];
            if(helper(nums,ind+1)) return true;
            b = b+nums[ind];
        }
        if(nums[ind]<=c){
            c = c-nums[ind];
            if(helper(nums,ind+1)) return true;
            c = c+nums[ind];
        }
        if(nums[ind]<=d){
            d = d-nums[ind];
            if(helper(nums,ind+1)) return true;
            d = d+nums[ind];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        long long int sum=0;
        for(auto i:nums)sum+=i;
        if(sum%4!=0) return false;
        sum=sum/4;
        a=sum;
        b=sum;
        c=sum;
        d=sum;
        sort(nums.rbegin(),nums.rend());
        return helper(nums,0);
    }
};