class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int firstElement = 0;
        int secondElement = 0;
        int firstCounter,secondCounter=0;
        firstCounter=0;
        secondCounter=0;
        for(auto i:nums){
            if(firstElement==i){
                firstCounter++;
            }
            else if(secondElement==i){
                secondCounter++;
            }
            else if(firstCounter==0){
                firstElement=i;
                firstCounter++;
            }
            else if(secondCounter==0){
                secondElement=i;
                secondCounter++;
            }
            else{
                firstCounter--;
                secondCounter--;
            }
        }
        int cnt1=0,cnt2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==firstElement) cnt1++;
            else if(nums[i]==secondElement) cnt2++;
        }
        if(cnt1>n/3) ans.push_back(firstElement);
        if(cnt2>n/3) ans.push_back(secondElement);
        return ans;
    }
};