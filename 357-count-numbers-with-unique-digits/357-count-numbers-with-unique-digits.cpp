class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        //if(n==0) return 0;
        if(n<=2){
            if(n==0) return 1;
            else if(n==1) return 10;
            else if(n==2) return 91;
        }
        vector<int>nonDuplicates(n+1);
        int duplicates,noOfDigits;
        int ps=0;
        nonDuplicates[0]=1;
        nonDuplicates[1]=9;
        nonDuplicates[2]=81;
        duplicates =9;

            for(int i=0; i<2+1; i++){
                ps = ps+nonDuplicates[i];
            }
            //return ps;
        
        for(int i=3; i<n+1; i++){
            noOfDigits = 9*(pow(10,i-1));
            duplicates=(nonDuplicates[i-1]*(i-1)) + (duplicates*10);
            nonDuplicates[i]=noOfDigits-duplicates;
            cout<<nonDuplicates[i];
            ps+=nonDuplicates[i];
            //duplicates = noOfDigits-nonDuplicates[i];
        }
        return ps;
    }
};