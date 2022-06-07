class Solution {
public:
    double findPower(double x, int n){
        double result = 1;
        while(n>0){
            if(n%2==1){
                result*=x;
            }
            x*=x;
            n/=2;
        }
        return result;
    }
    double myPow(double x, int n) {
        double ans=0;
        if(n<0){
            ans = findPower(x,abs(n));
            ans = 1/ans;
        }
        else{
            ans = findPower(x,n);
        }
        return ans;
    }
};