class Solution {
public:
    int brokenCalc(int startValue, int target) {
     
        int cnt=0;
        while(target>startValue){
            cnt++;
            if(target%2==1) target++;
            else target/=2;
        }
        if(startValue>target){
            cnt=cnt+(startValue-target);
        }
        return cnt;
    }
};