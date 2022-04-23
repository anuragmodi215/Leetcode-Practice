class Solution {
public:
    int possible(vector<int>& weights, int n, int mid){
        int cnt=1;
        int possibleWeight=0;
        for(int i=0; i<n; i++){
            possibleWeight+=weights[i];
            if(possibleWeight>mid){
                possibleWeight=weights[i];
                cnt++;
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low=0,high=0;
        for(int i=0; i<n; i++){
            high+=weights[i];
            low=max(low,weights[i]);
        }
        //cout<<low<<high;
        int res = 0;
        while(low<=high){
            int mid = (low+high)>>1;
            int possibility = possible(weights,n,mid);
            if(possibility==days){
                res = mid;
                high = mid-1;
            }
            if(possibility<days){
                high = mid-1;
            }
            else if(possibility>days){
                low = mid+1;
            }
        }
        return low;
    }
};