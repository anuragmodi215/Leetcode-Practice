class Solution {
public:
    static bool cmp(int a, int b){
        string x = to_string(a)+to_string(b);
        string y = to_string(b)+to_string(a);
        
        return x>y;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans = "";
        int n = nums.size();
        if(nums[0]==0) return "0";
        // for(auto i:nums)
        //     cout<<i<<" ";
            
        for(int i=0; i<n; i++){
            string temp = to_string(nums[i]);
            ans+=temp;
        }
       return ans;
    }
};