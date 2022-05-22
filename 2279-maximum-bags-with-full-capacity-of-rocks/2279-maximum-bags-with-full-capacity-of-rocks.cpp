class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int cnt=0;
        int n = capacity.size();
        vector<int>diff(n);
        for(int i=0; i<n; i++){
            diff[i] = capacity[i]-rocks[i];
        }
        sort(diff.begin(),diff.end());
        for(int i=0; i<n; i++){
            if(diff[i]==0) cnt++;
            else{
                if(additionalRocks>=diff[i]){
                    cnt++;
                    additionalRocks = additionalRocks-diff[i];
                }
                else break;
            }
        }
        return cnt;
    }
};