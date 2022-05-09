class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int thirdElement=INT_MIN;
        bool checkThirdElement=0;
        stack<int>st;
        int n=nums.size();
        for(int i=n-1; i>=0 ; i--){
            if(nums[i]<thirdElement) return true;
            else{
                while(!st.empty() and st.top()<nums[i]){
                    thirdElement = st.top(); 
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        return false;
    }
};