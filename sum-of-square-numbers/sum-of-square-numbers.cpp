class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int strt=0,end=sqrt(c);
        long long int sum;
        while(strt<=end){
            sum=strt*strt+end*end;
            if(sum==c) return true;
            else if(sum>c) end--;
            else strt++;
        }
        return false;
    }
};