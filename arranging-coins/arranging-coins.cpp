class Solution {
public:
    int arrangeCoins(int n) {
        long long int ans=0;
        long long int sum=0;
        for(long long int i=1; sum+i<=n; i++){
            sum+=i;
            ans++;
        }
        return ans;
    }
};