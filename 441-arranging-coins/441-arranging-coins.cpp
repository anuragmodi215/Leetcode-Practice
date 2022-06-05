class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1;
        int high = n;
        while(low<=high){
            long long int mid = low+(high-low)/2;
            long long int coins = mid*(mid+1)/2;
            if(coins == n){
                return mid;
            }
            else if(coins<n){
                low = mid+1;
            }
            else if(coins>n){
                high = mid-1;
            }
        }
        return high;
    }
};