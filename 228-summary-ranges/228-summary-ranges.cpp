class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string>v;
        if(n==0) return v;
        for(int i=0; i<n;i++){
            int end = i;
            while(end+1<n and nums[end]+1==nums[end+1]){
                end++;
            }
            if(end>i){
                string s;
                v.push_back(to_string(nums[i])+"->"+to_string(nums[end]));
                // s.push_back(nums[i]+'0');
                // s.push_back('-'); s.push_back('>');
                // s.push_back(nums[end]+'0');
                 //v.push_back(s);
                i = end;
            }
            else{
                
                v.push_back(to_string(nums[i]));
            }
        }
        return v;
    }
};