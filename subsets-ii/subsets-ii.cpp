class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
void solve(vector<int> input,vector<int>output, int i){
        if(i==input.size())
        {
            if(s.find(output)==s.end())
            {
                ans.push_back(output);
            }
            s.insert(output);
            return;
        }
    
            solve(input,output,i+1);
            output.push_back(input[i]);
            solve(input,output,i+1);
            
        }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>output;
        solve(nums,output,0);
        return ans;
    }
};