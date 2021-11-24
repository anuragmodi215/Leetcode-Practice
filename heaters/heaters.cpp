class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int n=houses.size();
        int len=heaters.size();
        vector<int>left(n,INT_MAX);
        //vector<int>right(n,INT_MAX);
        for(int i=0,j=0; i<n and j<len; ){
            if(houses[i]<=heaters[j]){
                left[i]=heaters[j]-houses[i];
                i++;
            }
            else j++;
        }
        
        for(int i=n-1,j=len-1; i>=0 and j>=0; ){
            if(houses[i]>=heaters[j]){
                left[i]=min(left[i],houses[i]-heaters[j]);
                i--;
            }
            else j--;
        }
        return *max_element(left.begin(),left.end());
    }
};