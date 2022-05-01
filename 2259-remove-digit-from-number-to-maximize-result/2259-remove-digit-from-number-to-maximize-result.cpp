class Solution {
public:
    string helper(string number, char digit){
        int n = number.size();
        int index=-1;
        string ans="0";
        for(int i=0; i<n; i++){
            if(number[i]==digit and i+1<n and number[i]<number[i+1]){
                index = i;
                break;
            }
        }
        if(index>-1){
            string a = number.substr(0,index);
            string b = number.substr(index+1);
            ans = a+b;
        }
        
        int lastInd = number.rfind(digit);
        string ans2=number.substr(0,lastInd)+number.substr(lastInd+1);
        
        if(ans<ans2) return ans2;
        else return ans;

    }
    string removeDigit(string number, char digit) {
        string a = helper(number,digit);
        return a;
    }
};