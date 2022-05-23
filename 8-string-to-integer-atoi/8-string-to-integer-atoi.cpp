class Solution {
public:
    int myAtoi(string s) {
        long long int myInt = 0;
        int n = s.size();
        bool isNeg = 0;
        int j=0;
                
        while(s[j]==' ')j++;
        if(s[j]=='-'){
                isNeg = 1;
                j++;
            }
        else if(s[j]=='+') j++;
        
        while(j<n){
            if(s[j]>='0' and s[j]<='9'){
                int rem = s[j]-'0';
                myInt = myInt*10+rem;
                if(!isNeg and myInt>=INT_MAX){
                    myInt = INT_MAX; 
                    break;
                } 
                else if(isNeg and myInt>INT_MAX){
                    myInt = INT_MIN;
                    break;
                }
                j++;
            }
            else break;
        }
        
        if(isNeg){
            myInt = myInt*(-1);
        }
        
     return myInt;   
    }
};