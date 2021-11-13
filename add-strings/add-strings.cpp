class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1;
        string ans="";
        int carry=0;
        while(i>=0 and j>=0){
            int x = num1[i]-'0';
            int y = num2[j]-'0';
            int sum = x+y+carry;
            carry = sum/10;
            int append = sum%10;
            ans = to_string(append)+ans;
            i--;j--;
        }
        while(i>=0){
                int x = num1[i]-'0';
                int sum = carry+x;
                carry = sum/10;
                int append = sum%10;
                ans = to_string(append)+ans;
            i--;
        }
        while(j>=0){
            int x = num2[j]-'0';
                int sum = carry+x;
                carry = sum/10;
                int append = sum%10;
                ans = to_string(append)+ans;
            j--;
        }
        if(carry>0){
            ans = to_string(carry)+ans;
        }
        return ans;
    }
};