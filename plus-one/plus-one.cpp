class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n = digits.size();
        digits[n-1]++;
        if(digits[n-1]>9){
        for(int i=n-1; i>=0; i--){
            if(i==0 and digits[i]>=9){
                digits[i]=0;
                digits.push_back(1);
                reverse(digits.begin(),digits.end());
                return digits;
            }
            int digit=digits[i];
            int sum = digit+carry;
            digits[i]=sum%10;
            carry = sum/10;
            if(carry==0) break;
            
        }
        }
        return digits;
    }
};