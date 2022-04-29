class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>output;
        sort(intervals.begin(), intervals.end());
        output.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=0; i<n; i++){
            if(output.back()[1]>=intervals[i][0]){
                output.back()[1] = max(output.back()[1],intervals[i][1]);
            }
            else{
                output.push_back(intervals[i]);
            }
        }
        return output;
    }
};