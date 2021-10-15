class Solution {
public:
    int trailingZeroes(int n) {
        int i=1;
        int x;
        int cnt=0;
        while(1){
            x=n/pow(5,i);
            if(x<=0) break;
            cnt+=x;
            i++;
        }
        return cnt;
    }
};