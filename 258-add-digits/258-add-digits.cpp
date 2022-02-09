class Solution {
public:
    int helper(int num){
        if(num<10) return num;
        int number=num;
        int sum=0;
        while(number>0){
            int remainder=number%10;
            sum+=remainder;
            number/=10;
        }
        return helper(sum);
    }
    int addDigits(int num) {
        return helper(num);
    }
};