class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]>b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),compare);
        int strt=intervals[0][0];
        int end=intervals[0][1];
        int n=intervals.size();
        int cnt=0;
        for(int i=1; i<n; i++){
            if(intervals[i][0]>=strt and end>=intervals[i][1]){
                cnt++;
            }
            else{
                strt=intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        return (n-cnt);
    }
};









