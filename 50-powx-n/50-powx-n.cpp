class Solution {
public:
    double helper(double x, int n){
        double result = 1;
        while(n>0){
                if(n%2==1)
                {
                    result = result*x;
                }
                x = x*x;
                n = n/2;
            }
        return result;
    }
    double myPow(double x, int n) {
        double ans=0;
        if(n<0){
            n = abs(n);
            ans = helper(x,n);
            ans = 1/ans;
        }
        else{
            ans = helper(x,n);
        }
        return ans;
    }
};