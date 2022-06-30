class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        
        int prevS=intervals[0][0];
        int prevE=intervals[0][1];
        int cnt=0;
        for(int i=1; i<n; i++){
            if(intervals[i][0]<prevE){
                cnt++;
            }
            else{
                prevS = intervals[i][0];
                prevE = intervals[i][1];
            }
        }
        return cnt;
    }
};