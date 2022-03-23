class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt=0;
        while(target>1 and maxDoubles>0){
            cnt++;
            if(target%2==0){
                target = target/2;
                maxDoubles--;
                }
            else target=target-1;
        }
        if(target>1){
            cnt=cnt+target-1;
        }
        return cnt;
    }
};