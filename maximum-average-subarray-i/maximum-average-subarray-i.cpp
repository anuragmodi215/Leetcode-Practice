class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         double sum=0,tot=INT_MIN;
        int i=0,j=0;
        int n=nums.size();
        while(j<n){
            if(j-i+1<k){
                sum+=nums[j];
                j++;
            }
            else if(j-i+1==k){
                sum=sum+nums[j];
                tot=max(sum,tot);
                sum=sum-nums[i];
                
                
                i++;j++;
            }
        }
        cout<<tot;
        sum=tot;
        return sum/k;
    }
};