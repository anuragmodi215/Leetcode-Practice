class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int temp=0;
        for(int i=0; i<n-1; i++){
            if(nums[i]<=nums[i+1]){
                temp = nums[i];
            }
            else{
                if(nums[i+1]<temp){
                    nums[i+1] = nums[i];
                }
                count++;
                if(count>1) return false;
            }
        }
        
        return true;
    }
};



// [4,2,3]      true
// [4,2,1]  false
// [3,4,2,3] false
// [-1,4,2,3] true
// [5,7,1,8] true