class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        long long int low = 0;
        long long int high = x-1;
        while(low<=high){
            long long int mid = (low+high)>>1;
            if(mid*mid==x) return mid;
            else if(mid*mid>x){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        if(high>0)
            return high;
        return 0;
    }
};