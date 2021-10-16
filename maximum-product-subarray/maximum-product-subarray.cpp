class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long pro=1,tot=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            pro*=(long long )nums[i];
            tot=max(tot,pro);
             if(pro==0) pro=1;
        }
        //long long x=pro;
        pro=1;
        for(int i=nums.size()-1; i>=0; i--){
            pro*=(long long )nums[i];
            tot=max(tot,pro);
            if(pro==0) pro=1;
        }
      
        return (int)(tot);
    }
};