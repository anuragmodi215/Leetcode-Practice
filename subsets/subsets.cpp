class Solution {
public:
    vector<vector<int>>v;
    void solve(vector<int>input, vector<int>output,int i){
        if(input.size()==i)
        {
            v.push_back(output);
            return;
        }
        
        
        //input.erase(input.begin(),input.begin()+i);
      
        solve(input,output,i+1);
        output.push_back(input[i]);
        solve(input,output,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<int>input(nums);
        solve(input,output,0);
        return v;
    }
};