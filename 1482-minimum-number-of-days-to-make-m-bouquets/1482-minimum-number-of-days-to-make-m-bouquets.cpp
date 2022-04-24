class Solution {
public:
    
    bool canMake(int mid, int n, int m, int k, vector<int>& bloomDay){
        int flowers=0;
        int bouquets=0;
        
        for(int i=0; i<n; i++){
            if(bloomDay[i]<=mid){
                flowers++;
            }
            else{
                flowers=0;
            }
            if(flowers==k){
               bouquets++;
               flowers=0;
            } 
        }
        //cout<<bouquets<<endl;
        if(bouquets>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        int low=INT_MAX,high=INT_MIN,mid;
        for(int i=0; i<n; i++){
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }
        int res = -1;
        while(low<=high){
            mid = (low+high)>>1;
            
            if(canMake(mid,n,m,k,bloomDay)){
                res=low;
                high = mid-1;
            }
            else low = mid+1;
        }
        if(res>-1) return low;
        else return -1;
    }
};