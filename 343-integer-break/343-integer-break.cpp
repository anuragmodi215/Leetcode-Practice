class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        long long int product=1;
        while(n>4){
            n-=3;
            product*=3;
        }
        return product*=n;
    }
};